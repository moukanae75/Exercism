export function age(planet: unknown, seconds: unknown): unknown {
    if (typeof seconds !== 'number') {
        return null
    }
    const earthYearInSeconds = 31557600;
    return planet === 'earth'? Math.round(seconds/earthYearInSeconds/1.0*100)/100:
    planet === 'mercury'? Math.round(seconds/earthYearInSeconds/0.2408467*100)/100:
    planet === 'venus'? Math.round(seconds/earthYearInSeconds/0.61519726*100)/100:
    planet === 'mars'? Math.round(seconds/earthYearInSeconds/1.8808158*100)/100:
    planet === 'jupiter'? Math.round(seconds/earthYearInSeconds/11.862615*100)/100:
    planet === 'saturn'? Math.round(seconds/earthYearInSeconds/29.447498*100)/100:
    planet === 'uranus'? Math.round(seconds/earthYearInSeconds/84.016846*100)/100:
    planet === 'neptune'? Math.round(seconds/earthYearInSeconds/164.79132*100)/100:
    null;

}
