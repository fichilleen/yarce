all:
	g++ -g bit_board.cc test_pieces.cc draw_board.cc shift_test.cc types.cc identify_piece.cc\
		-Wall
clean:
	$(RM) a.out core* *gch
