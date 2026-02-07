from typing import List,Optional
from pydantic import BaseModel, model_validator

class Grid (BaseModel):
    row: int
    col: int
    mat : Optional[List[List]] = None

    @model_validator(mode='after')
    def validate_input(self):
        if (self.row != self.col):
            raise ValueError('row must be equal to col')
        return self
    
    @model_validator(mode='after')
    def initialize_mat(self):
        self.mat = [['-' for _ in range(self.col)] for _ in range(self.row)]
        self.print()
        return self

    def getCell(self,row:int, col:int):
        return self.mat[row][col]
    
    def setCell(self, row:int, col:int, val):
        self.mat[row][col] = val
    

    def getRow(self):
        return self.row
    
    def getCol(self):
        return self.col
    
    def print(self):
        for i in range(self.getRow()):
            for j in range(self.getCol()):
                print(self.getCell(i,j) + " ",end=" ")
            print("\n")


