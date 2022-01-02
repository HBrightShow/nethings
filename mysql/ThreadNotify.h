#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <stdint.h>
#include <pthread.h>

namespace mysql {

class CThreadNotify {

public:
	CThreadNotify();

	void lock(); 
	void unLock(); 
	void wait(); 
	void init();
	void signal() {
		pthread_cond_signal(&m_cond);
	}
	int waitTime(int ms);

	~CThreadNotify();
	
private:

	pthread_mutex_t m_mutex;		
	pthread_mutexattr_t m_mutexAttr;
	pthread_cond_t m_cond;	
};

};

#endif



