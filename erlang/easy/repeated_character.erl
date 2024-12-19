-module(repeated_character).

-export([repeated_character/1]).

-spec repeated_character(S :: unicode:unicode_binary()) -> char().
repeated_character(S) ->
  List = binary_to_list(S),
  repeated_character(List, 0).

repeated_character([H | T], Set) ->
  Offset = H - $a,
  NewSet = Set band (1 bsl Offset),
  case Set =:= NewSet of
    true ->
      H;
    _ ->
      repeated_character(T, NewSet)
  end.
