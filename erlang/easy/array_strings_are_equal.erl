-module(array_strings_are_equal).

-spec array_strings_are_equal(Word1 :: [unicode:unicode_binary()],
                              Word2 :: [unicode:unicode_binary()]) ->
                               boolean().
array_strings_are_equal(Word1, Word2) ->
  array_strings_are_equal(Word1, Word2, 0, 0).

array_strings_are_equal([], [], _, _) ->
  true;
array_strings_are_equal([], _, _, _) ->
  false;
array_strings_are_equal(_, [], _, _) ->
  false.

array_strings_are_equal( [ H1 | T1 ] , [ H2 | T2 ] , length( H1 ) , length( H2 ) ) -> to .
