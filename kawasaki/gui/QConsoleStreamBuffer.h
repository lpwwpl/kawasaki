#ifndef QCONSOLESTREAMBUFFER_H
#define QCONSOLESTREAMBUFFER_H

#include <streambuf>
#include <QMutex>
#include <QMutexLocker>

#include "IConsole.h"

//-------------------------------------------------------------------------------------------------
//
// This code is based on the class editlog_stream.h written by Daniel Lohmann.
// It was modified in order to redirect the standard output to a QCommandPrompt
// object
//
// Modifications made by me (20120906; Ingo Berg):
//
// - class is no longer in namespace std
// - comments changed into doxygen format
// - Dependencies from Windows API removed and replaced
//   with corresponding qt lib functions
// - function definitions moved into class definition
//
// original Copyright Message (verbatim):

/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
\ editlog_stream.h,  Use C++ std-library to write into a Windows Edit-Control
/
\ Version:	1.0, created 2000-04-02
/ Author:	Daniel Lohmann (daniel@uni-koblenz.de)
\
/ Please send comments and bugfixes to the above email address.
\
/ This code is provided AS IS, you use it at your own risk!
\ You may use it for whatever you want.
/
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/


//-------------------------------------------------------------------------------------------------
/** \brief basic_streambuf class, that writes output to a IConsole

    This class is save to be used for output from multiple threads.
*/
template <class E, class T = std::char_traits<E>, int BUF_SIZE = 512 >
class basic_editstreambuf : public std::basic_streambuf<E, T>
{
public:
    typedef typename std::basic_streambuf<E, T>::int_type int_type;
    typedef typename std::basic_streambuf<E, T>::char_type char_type;
    typedef typename std::basic_streambuf<E, T>::traits_type traits_type;

    //---------------------------------------------------------------------------------------------
    basic_editstreambuf(IConsole *pConsole)
        :std::basic_streambuf<E,T>()
        ,m_pConsole(pConsole)
        ,m_mutex(QMutex::Recursive)
    {
        psz = new char_type[BUF_SIZE];
        this->setbuf(psz, BUF_SIZE);

        // leave place for single char + 0 terminator
        this->setp( psz, psz + BUF_SIZE - 2 );
    }

    //---------------------------------------------------------------------------------------------
    virtual ~basic_editstreambuf()
    {
        delete psz;
    }

protected:

    //---------------------------------------------------------------------------------------------
    virtual int_type overflow(int_type c = T::eof() )
    {
        QMutexLocker lock(&m_mutex);

        char_type* plast = this->pptr();

        if( c != T::eof() )
            *plast++ = c;

        *plast = char_type();

        // Pass text to the edit control
        m_pConsole->addLine(this->pbase());

        setp( this->pbase(), this->epptr() );

        return c != (T::eof()) ? T::not_eof(c) : T::eof();
    }

    //---------------------------------------------------------------------------------------------
    virtual int sync()
    {
        overflow();
        return 0;
    }

    //---------------------------------------------------------------------------------------------
    virtual std::streamsize xsputn(const char_type* pch, std::streamsize n)
    {
        QMutexLocker lock(&m_mutex);

        std::streamsize nMax, nPut;

        for(nPut = 0; 0 < n; )
        {
            if (this->pptr() != 0 && 0 < (nMax = this->epptr() - this->pptr()) )
            {
                if (n < nMax)
                    nMax = n;

                traits_type::copy(this->pptr(), pch, nMax);

                // Sync if string contains LF
                bool bSync = traits_type::find(pch,
                                               nMax,
                                               traits_type::to_char_type( '\n' ) ) != NULL;
                pch  += nMax;
                nPut += nMax;
                n    -= nMax;
                this->pbump(nMax);

                if( bSync )
                   sync();
            }
            else if (traits_type::eq_int_type(traits_type::eof(),
                                              overflow(traits_type::to_int_type(*pch))))
            {
                break;
            }
            else
            {
                ++pch;
                ++nPut;
                --n;
            }
        }

        return nPut;
    }

    char_type*	psz;
    IConsole *m_pConsole;
    QMutex m_mutex;
};

// Ansi version
typedef basic_editstreambuf<char> console_streambuf;

// Unicode version
typedef basic_editstreambuf<wchar_t> wconsole_streambuf;

#endif // QCONSOLESTREAMBUFFER_H
