from pydantic import BaseModel

class Move (BaseModel):
    serial_number: int
    row : int
    col: int