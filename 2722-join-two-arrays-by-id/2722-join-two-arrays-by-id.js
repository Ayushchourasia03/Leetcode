function join(arr1, arr2) {
    const r = (acc, x) => {
        acc[x.id] = x;
        return acc;
    };

    const d = arr1.reduce(r, {});

    arr2.forEach(x => {
        if (d[x.id]) {
            Object.assign(d[x.id], x);
        } else {
            d[x.id] = x;
        }
    });

    return Object.values(d);
}