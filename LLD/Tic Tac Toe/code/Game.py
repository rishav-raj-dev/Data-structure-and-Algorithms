from pydantic import BaseModel
from typing import List, Optional
from Player import Player
from Grid import Grid
from Move import Move

class Game (BaseModel):
    player1: Optional[Player] = None
    player2: Optional[Player] = None
    grid: Optional[Grid] = None
    moves: List[Move] = [] # stores the move history.
    move_count: int = 0 # count the number of moves
    Winner: Optional[Player] = None
    player1_move: bool = False # flag to decide whose turn this is.

    # setup the game with player name and board
    def setup(self,player1_name:str, player2_name: str, grid_rows: int, grid_cols:int):
        self.player1 = Player(name=player1_name)
        self.player2 = Player(name=player2_name)
        self.grid = Grid(row=grid_rows, col=grid_cols)
        self.player1_move = True # player 1 gets the first move
    
    def validate(self,row:Optional[int] = None, col:Optional[int] = None):
        # objective of fn - to validate if the move is vaid or if there is any legal position left.
        if (row is None and col is None):
            valid = False
            rows = self.grid.getRow()
            cols = self.grid.getCol()
            for i in range(rows):
                for j in range(cols):
                    if (self.grid.getCell(i,j)=='-'):
                        valid = True
                        return valid
            return valid
        if (row is None or col is None):
            raise ValueError("Invalid value for row and column is provided.")
        grid_row = self.grid.getRow()
        grid_col = self.grid.getCol()
        if (row <= 0 or col <= 0):
            raise ValueError("Input cannot be negative or zero.")
        elif (row > grid_row or col > grid_col):
            raise ValueError("Input row or col can't be greater than game grid.")

    def isWinner(self):
        # the objective is to check if the current player is winner or not.
        Winner = True
        # check all the rows
        for i in range(self.grid.getRow()):
            Winner = True
            for j in range(1,self.grid.getCol()):
                if (self.grid.getCell(i,j-1)!=self.grid.getCell(i,j) or self.grid.getCell(i,j)=='-'):
                    Winner = False
                    break
            if (Winner): 
                return Winner
        
        Winner = True
        # check all the cols
        for j in range(self.grid.getCol()):
            Winner = True
            for i in range(1,self.grid.getRow()):
                if (self.grid.getCell(i-1,j)!=self.grid.getCell(i,j) or self.grid.getCell(i,j)=='-'):
                    Winner = False
                    break
            if (Winner):
                return Winner
        
        Winner = True
        # check the diagonals
        for i in range(1,self.grid.getRow()):
            if (self.grid.getCell(i-1,i-1)!=self.grid.getCell(i,i) or self.grid.getCell(i,j)=='-' or self.grid.getCell(i-1,i-1)=='-'):
                Winner = False
                break
        if (Winner): 
            
            return Winner
        Winner = True
        row = self.grid.getRow()
        for i in range(1,self.grid.getRow()):
            if (self.grid.getCell(i,row-i-1)!=self.grid.getCell(i-1,row-i) or self.grid.getCell(i,j)=='-' or self.grid.getCell(i-1,i-1)=='-'):
                Winner = False
                break
        if (Winner): 
            return Winner
        return False
        
    def make_move(self, row:int, col:int):
        self.grid.setCell(row-1,col-1,'X' if self.player1_move else 'O')
        self.move_count += 1
        self.moves.append({self.move_count, row, col})

    def start(self):
        isGridValid  = self.validate()
        while(isGridValid):
            try:
                print(f"{self.player1.name if (self.player1_move) else self.player2.name}'s Move.")
                row, col = input("Please Enter Move (row col) ((-1, -1) for resignation): ").split()
                row = int(row)
                col = int(col)
                # for resignation
                if (row == -1 and col == -1):
                    self.Winner = self.player2 if (self.player1_move) else self.player1
                    print(f'{self.player1.name if (self.player1_move) else self.player2.name} resigned.')
                    break
                self.validate(row, col)
                self.make_move(row, col)
                isWinner = self.isWinner()
                if (isWinner): 
                    self.Winner = self.player1 if (self.player1_move) else self.player2
                    print(f'{self.player1.name if (self.player1_move) else self.player2.name} won the game.') 
                    break
                self.player1_move = not self.player1_move
                self.grid.print()
                isGridValid = self.validate()
            except Exception as e:
                print(e)
                print("Error occured.")
                continue

                  

