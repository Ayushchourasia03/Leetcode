var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        let cnt = 0;
        const ans = new Array(functions.length);

        if (functions.length === 0) {
            resolve([]);
            return;
        }

        for (let i = 0; i < functions.length; ++i) {
            functions[i]()
                .then(res => {
                    ans[i] = res;
                    cnt++;

                    if (cnt === functions.length) {
                        resolve(ans);
                    }
                })
                .catch(err => {
                    reject(err);
                });
        }
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))]);
 * promise.then(console.log); // [42]
 */