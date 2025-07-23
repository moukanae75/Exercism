export class Matrix {
    public data: number[][];
    
    constructor(input: string) {
        this.data = input.split('\n').map(row => row.split(' ').map(Number));
    }

    get rows(): number[][] {
        return this.data;
    }

    get columns(): number[][] {
        const result: number[][] = [];
        

        const numCols = this.data[0].length;
        

        for (let colIndex = 0; colIndex < numCols; colIndex++) {
            const column: number[] = [];
            
            // اجمع العنصر من كل صف
            for (let rowIndex = 0; rowIndex < this.data.length; rowIndex++) {
                column.push(this.data[rowIndex][colIndex]);
            }
            
            result.push(column);
        }
        
        return result;
    }
}
