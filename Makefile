all:
	g++ BitBoard.cc test_pieces.cc draw_board.cc shift_test.cc -Wall
clean:
	rm a.out core *gch
	# Cores might exist from purposely negative tests on asserts
