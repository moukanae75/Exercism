export function isLeap(n :number): boolean {
    if (n % 4 === 0) {
        if (n % 100 === 0) {
            return n % 400 === 0;
        }
        return true;
    }
    return false;
}
