#ifndef WEBSERVER_NONCAPYABLE_H_
#define WEBSERVER_NONCAPYABLE_H_

class Noncopyable
{
protected:
    Noncopyable() = default;
    ~Noncopyable() = default;

private:
    Noncopyable(const Noncopyable &) = delete;
    const Noncopyable &operator=(const Noncopyable &) = delete;
};

#endif  //WEBSERVER_NONCAPYABLE_H_