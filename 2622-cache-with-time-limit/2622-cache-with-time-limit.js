var TimeLimitedCache = function () {
    this.cache = new Map();
};

TimeLimitedCache.prototype.set = function (key, value, duration) {
    const isExist = this.cache.has(key);

    if (!this.isExpired(key)) {
        this.cache.set(key, [value, Date.now() + duration]);
    }

    return isExist;
};

TimeLimitedCache.prototype.get = function (key) {
    if (this.isExpired(key)) return -1;
    return this.cache.get(key)?.[0] ?? -1;
};

TimeLimitedCache.prototype.count = function () {
    let count = 0;
    for (const [key] of this.cache) {
        if (!this.isExpired(key)) count++;
    }
    return count;
};

TimeLimitedCache.prototype.isExpired = function (key) {
    return (
        this.cache.has(key) &&
        (this.cache.get(key)?.[1] ?? Number.NEGATIVE_INFINITY) < Date.now()
    );
};

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache();
 * obj.set(1, 42, 1000);
 * obj.get(1);
 * obj.count();
 */