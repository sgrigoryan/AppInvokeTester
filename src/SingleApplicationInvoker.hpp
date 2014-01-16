/*
 * SingleApplicationInvoker.hpp
 *
 *  Created on: Jan 14, 2014
 *      Author: sgrigoryan
 */

#ifndef SINGLEAPPLICATIONINVOKER_HPP_
#define SINGLEAPPLICATIONINVOKER_HPP_

#include <QObject>


class QTimer;

namespace bb { namespace system { class InvokeTargetReply; }}
/**
 * Class for invoking application
 */
class SingleApplicationInvoker:public QObject{
	Q_OBJECT
public:

	/**
	 * create the singleton
	 */
	static SingleApplicationInvoker& instance();

	/**
	 * destory the instance
	 */
	static void destoryInstance();

	/**
	 * Invoke url for target which will be invoked during start
	 */
	void setTargetUrl(const QString& target) {
		m_targetUrl = target;
	}

	/**
	 * Invoke app and start timer
	 */
	void start();

	/**
	 * stop running and close app if opened
	 */
	void stop();

public Q_SLOTS:


	/**
	 * time to close app and start new again after some delay
	 */
	void onScheduleTimeout();

	/**
	 * time to restart app again
	 */
	void onDelayerTimeout();



	/**
	 * checks results of invoke request
	 */
	void onInvokeResult();

	/**
	 * invoke request for app
	 */
	void invokeApp();

private:

	/**
	 * constructor
	 */
	SingleApplicationInvoker();

	/**
	 * copy constructor
	 */
	SingleApplicationInvoker(const SingleApplicationInvoker&);

	/**
	 * destructor
	 */
	~SingleApplicationInvoker();



private:
	static SingleApplicationInvoker* m_theInstance;

	QTimer* m_invokeScheduler;// the invoke scheduler

	bb::system::InvokeTargetReply *m_invokeTargetReply;
	QString m_targetUrl;

};


#endif /* SINGLEAPPLICATIONINVOKER_HPP_ */
