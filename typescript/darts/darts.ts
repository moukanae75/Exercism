export function score(x: unknown, y: unknown): unknown {

  
  const xNum = Number(x);
  const yNum = Number(y);

  const distanceSquared = Math.pow(xNum,2) + Math.pow(yNum,2);

  if (distanceSquared > 100) {
    return 0; 
  } else if (distanceSquared > 25) {
    return 1; 
  } else if (distanceSquared > 1) {
    return 5; 
  } else {
    return 10;
  }
}
