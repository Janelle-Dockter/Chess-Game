cmake_minimum_required(VERSION 3.13)
project(Chess_Game)

set(CMAKE_CXX_STANDARD 11)

add_executable(Chess_Game chess.cpp ChessMove.cpp Player.cpp )#Piece.cpp Square.cpp Board.cpp Rook.cpp King.cpp Queen.cpp Bishop.cpp
        #ChessGame.cpp Knight.cpp Pawn.cpp Castle.cpp Capture.cpp ConvertPawn.cpp)