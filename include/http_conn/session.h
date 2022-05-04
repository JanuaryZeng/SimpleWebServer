//
// Created by zxj on 2022/5/4.
//

#ifndef SIMPLESERVER_SESSION_H
#define SIMPLESERVER_SESSION_H

#include <openssl/md5.h>
#include <time.h>
#include <string>
#include <list>
#include <map>

#include "../lock/lock.h"

enum LOGIN_STATUS
{
    LOGIN = 0,
    UNLOGIN,
    FIRST_LOGIN
};

struct User
{
    std::string username;
    std::string sessionid;
    LOGIN_STATUS status;
    time_t last_time;
};

class Session
{
public:
    Session(int capacity, int timeout):cap(capacity), timeout(timeout){}
    LOGIN_STATUS get_status(std::string sessionid){
        MutexLockGuard lock(mutex);
        if(cache.count(sessionid)){
            movetotop(sessionid);
            return cache[sessionid]->status;
        }
        return UNLOGIN;
    }

    std::string get_username(string sessionid){
        MutexLockGuard lock(mutex);
        if(cache.count(sessionid)){
            movetotop(sessionid);
            return cache[sessionid]->username;
        }
        return "";
    }

    std::string put(std::string username){
        MutexLockGuard lock(mutex);
        std::string sessionid = MD5(username);
        if (!cache.count(sessionid)){
            if (users.size() >= cap){
                cache.erase(users.back().sessionid);
                users.pop_back();
            }
            User user;
            user.username = username;
            user.sessionid = sessionid;
            user.last_time = time(NULL);
            user.status = LOGIN;
            users.push_front(user);
            cache[sessionid] = users.begin();
        }
        cache[sessionid]->status = LOGIN;
        deltimeout();
        return sessionid;
    }

private:

    void movetotop(std::string key){
        auto p = *cache[key];
        users.erase(cache[key]);
        users.push_front(p);
        cache[key] = users.begin();
        users.front().last_time = time(NULL);
        dealtimeout();
    }

    void dealtimeout(){
        time_t curtime = time(NULL);
        while(!users.empty() && users.back().last_time + timeout * 60 < curtime){
            cache.erase(users.back());
            users.pop_back();
        }
    }

    std::string MD5(const std::string &src){
        MD5_CTX ctx;

        std::string md5_string;
        unsigned char md[16] = {0};
        char tmp[40] = {0};
        std::string code = src + to_string(time(NULL));
        MD5_Init(&ctx);
        MD5_Update(&ctx, code.c_str(), code.size());
        MD5_Final(md, &ctx);
        for(int i = 0; i < 16; ++i){
            memset(tmp, 0x00, sizeof(tmp));
            sprintf(tmp, "%02X", md[i]);
            md5_string += tmp;
        }
        return md5_string;
    }

    typedef std::list<User> List;
    size_t cap;
    int timeout;
    List users;
    std::map<std::string, List::iterator> cache;
    locker mutex;
};

#endif //SIMPLESERVER_SESSION_H
