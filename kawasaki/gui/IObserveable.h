#ifndef IOBSERVEABLE_H
#define IOBSERVEABLE_H

//--- Standard includes ---------------------------------------------------------------------------
#include <list>
#include <algorithm>


template<typename T>
class IObserveable
{
public:

    //---------------------------------------------------------------------------------------------
    void attachObserver(T* pObs)
    {
        if (std::find(m_observer.begin(), m_observer.end(), pObs)==m_observer.end())
        {
            m_observer.push_back(pObs);
        }
    }

    //---------------------------------------------------------------------------------------------
    void detachObserver(T* pObs)
    {
        m_observer.remove(pObs);
    }

    //---------------------------------------------------------------------------------------------
    void detachAllObservers()
    {
        m_observer.clear();
    }

    //---------------------------------------------------------------------------------------------
    bool hasObservers() const
    {
        return m_observer.size()!=0;
    }

protected:
    typedef std::list<T*> obs_list;
    obs_list m_observer;
};

#endif // IOBSERVEABLE_H
