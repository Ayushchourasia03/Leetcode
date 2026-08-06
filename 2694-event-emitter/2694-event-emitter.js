class EventEmitter {
    constructor() {
        this.d = new Map();
    }

    subscribe(eventName, callback) {
        if (!this.d.has(eventName)) {
            this.d.set(eventName, new Set());
        }

        this.d.get(eventName).add(callback);

        return {
            unsubscribe: () => {
                this.d.get(eventName)?.delete(callback);
            },
        };
    }

    emit(eventName, args = []) {
        const callbacks = this.d.get(eventName);

        if (!callbacks) {
            return [];
        }

        return [...callbacks].map(callback => callback(...args));
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * function onClickCallback() {
 *     return 99;
 * }
 *
 * const sub = emitter.subscribe("onClick", onClickCallback);
 *
 * console.log(emitter.emit("onClick")); // [99]
 * sub.unsubscribe();
 * console.log(emitter.emit("onClick")); // []
 */