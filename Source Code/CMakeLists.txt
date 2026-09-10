cmake_minimum_required(VERSION 3.13)
project(Chess_Game_WORK)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess_Game_WORK Bishop.cpp Board.cpp chess.cpp ChessGame.cpp King.cpp Knight.cpp Pawn.cpp Piece.cpp
        Player.cpp Queen.cpp Rook.cpp Square.cpp)