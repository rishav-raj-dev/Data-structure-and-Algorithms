

from Game import Game

game = Game()
player1 = input("Player 1 Name: ")
player2 = input("Player 2 Name: ")
rows = 3
cols = 3
game.setup(player1_name=player1, player2_name=player2, grid_rows=rows, grid_cols=cols)
game.start()
