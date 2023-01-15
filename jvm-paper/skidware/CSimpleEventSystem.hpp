#ifndef CSIMPLEEVENTSYSTEM_HPP_GUARD
#define CSIMPLEEVENTSYSTEM_HPP_GUARD
#pragma once

#include "common.h"

typedef struct CSimpleEvent {
protected:
	virtual ~CSimpleEvent() = default;
} CSimpleEvent;

typedef struct CCancellableEvent : CSimpleEvent {
	bool isCancelled = false;

	void cancelEvent() {
		this->isCancelled = true;
	}
} CCancellableEvent;

typedef struct CEventListener {
	virtual void onEvent(const CSimpleEvent*) {}
} CEventListener;

typedef struct CSimpleEventManager {
	void registerListener(CEventListener* listener) {
		listeners.insert(listener);
	}
	void unregisterListener(CEventListener* listener) {
		listeners.erase(listener);
	}
	void callEvent(const CSimpleEvent* event) {
		for (CEventListener* listener : listeners) {
			listener->onEvent(event);
		}
	}

	std::set<CEventListener*> listeners;
} CSimpleEventManager;

typedef struct UpdateEvent : CSimpleEvent {

} CUpdateEvent;

typedef struct Render2DEvent : CSimpleEvent {
	Render2DEvent(HDC hdc) : hdc(hdc) {
		this->hdc = hdc;
	}
	HDC hdc;
} CRender2DEvent;

#endif //CSIMPLEEVENTSYSTEM_HPP_GUARD
