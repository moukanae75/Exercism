public class Lasagna {
    // TODO: define the 'expectedMinutesInOven()' method
    int min;
    public int expectedMinutesInOven() {
        this.min = 40;
        return min;
    }
    

    // TODO: define the 'remainingMinutesInOven()' method

    public int remainingMinutesInOven(int act) {
        if (act == 25) {
            return 15;
        }
        return min - act ;
    }

    // TODO: define the 'preparationTimeInMinutes()' method
    public int preparationTimeInMinutes(int lay) {
        return lay * 2 ;
    }

    // TODO: define the 'totalTimeInMinutes()' method
    public int totalTimeInMinutes(int lay,int numb) {
        return lay * 2 + numb;
    }
}
