all:
	g++ BitBoard.cc test_pieces.cc draw_board.cc shift_test.cc -Wall
clean:
	$(RM) a.out core *gch
