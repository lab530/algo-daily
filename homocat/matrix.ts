
// helper class to make code more reable
class Cell {
  row: number;
  col: number;
  stepsFromZero: number;

  constructor(row: number, col: number, stepsFromZero: number) {
      this.row = row;
      this.col = col;
      this.stepsFromZero = stepsFromZero;
  }

  // checks if cell is in bounds of matrix
  isInBounds(mat: number[][]) {
      return (
          (this.row < mat.length)
          && (this.row >= 0)
          && (this.col < mat[0].length)
          && (this.col >= 0)
      );
  }
  
  // get cardinal direciton neighours of a cell
  getNeighbours(): Cell[] {
      return (
          [
              new Cell(this.row - 1, this.col, this.stepsFromZero + 1), // North
              new Cell(this.row + 1, this.col, this.stepsFromZero + 1), // South
              new Cell(this.row, this.col - 1, this.stepsFromZero + 1), // West
              new Cell(this.row, this.col + 1, this.stepsFromZero + 1) // East
          ]
      );
  }
}

// place holder value for an un touched cell, avoids us needing to use a set to keep track of what cells we have seen
const UNFILLED_CELL: number = -Infinity;

function fill01Matrix(queue: Cell[], result: number[][], mat: number[][]): void {
  while(queue.length > 0) {
      const entry: Cell = queue.shift();

      const neighbours = entry.getNeighbours();

      for (let neighbour of neighbours) {
          // if this cell is in-bounds, and unfilled, that means it's a 1 that needs to be filled, and it's neighbours must be searched
          if (neighbour.isInBounds(result) && result[neighbour.row][neighbour.col] === UNFILLED_CELL) {
              // fill result
              result[neighbour.row][neighbour.col] = entry.stepsFromZero + 1;             
              // push on queue to process 
              queue.push(new Cell(neighbour.row, neighbour.col, entry.stepsFromZero + 1));
          }
      }
  }
}

function updateMatrix(mat: number[][]): number[][] {
  let result: number[][] = [];
  let queue: Cell[] = [];

  for(let row = 0; row < mat.length; row++) {
      result.push([]);
      for(let col = 0; col < mat[0].length; col++) {
          // marks the non-zeros as unfilled
          result[row][col] = (mat[row][col] === 0) ? 0 : UNFILLED_CELL;
          if (result[row][col] === 0) {
              // we only want to process the 0s
              queue.push(new Cell(row, col, 0));
          }
      }
  }

  fill01Matrix(queue, result, mat);

  return result;
};