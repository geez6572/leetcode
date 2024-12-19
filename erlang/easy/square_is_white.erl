-module(square_is_white).

-spec square_is_white(Coordinates :: unicode:unicode_binary()) -> boolean().
square_is_white(Coordinates) ->
  CharList = unicode:characters_to_list(Coordinates),
  First = lists:nth(0, CharList),
  Second = lists:nth(1, CharList),
  (First - a + Second - '1') rem 2 == 1.
