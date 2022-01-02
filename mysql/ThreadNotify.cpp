#include "ThreadNotify.h"


using namespace mysql;

CThreadNotify::CThreadNotify()
{
	init();
}
void CThreadNotify::init(){
	
	pthread_mutexattr_init(&m_mutexAttr);
	pthread_mutexattr_settype(&m_mutexAttr, PTHREAD_MUTEX_RECURSIVE);

	pthread_mutex_init(&m_mutex, &m_mutexAttr);
	pthread_cond_init(&m_cond, NULL);
}
void CThreadNotify::lock()
{
	 pthread_mutex_lock(&m_mutex); 
}

void CThreadNotify::unLock()
{
	pthread_mutex_unlock(&m_mutex);
}

void CThreadNotify::wait()
{
	pthread_cond_wait(&m_cond, &m_mutex);
}

int CThreadNotify::waitTime(int ms)
{
	struct timespec outtime;
	clock_gettime(CLOCK_MONOTONIC, &outtime);

	outtime.tv_nsec += ms / 1000;

	uint64_t us = outtime.tv_nsec / 1000 + 1000 * (ms % 1000);
	outtime.tv_sec += us / 1000000;
	outtime.tv_nsec = us * 1000;
	us = us % 1000000;
	return pthread_cond_timedwait(&m_cond, &m_mutex, &outtime);
}

CThreadNotify::~CThreadNotify()
{
	
		pthread_mutexattr_destroy(&m_mutexAttr);
		pthread_mutex_destroy(&m_mutex);
		pthread_cond_destroy(&m_cond);
	
}
