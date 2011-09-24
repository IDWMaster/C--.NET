#ifndef CPROPERTY_H
#define CPROPERTY_H
//Thank You! Credit goes to Skorj at http://www.cplusplus.com/forum/general/8147/
//for contributing this code to the development community!
/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
template<class T,
         class Y>
class Property
{
    typedef T (Y::* _pmGet_t)() const;
    typedef void (Y::* _pmSet_t)(T);

    Y& m_objInstance;
    _pmGet_t     m_pmGet;
    _pmSet_t     m_pmSet;

public:
    Property(Y& objInstance, _pmGet_t pmGet, _pmSet_t pmSet)
    :  m_objInstance(objInstance), m_pmGet(pmGet), m_pmSet(pmSet)
    {}
    operator T() { return (m_objInstance.*m_pmGet)(); }
    void operator =(T value) { (m_objInstance.*m_pmSet)(value); }
};

#endif // CPROPERTY_H



