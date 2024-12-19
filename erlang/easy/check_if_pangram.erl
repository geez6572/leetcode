-module(check_if_pangram).

-spec check_if_pangram(Sentence :: unicode:unicode_binary()) -> boolean().
check_if_pangram(Sentence) ->
  Map = #{},
  List = bitstring_to_list(Sentence),
  recur(List, Map).

-spec recur(Sentence :: unicode:unicode_binary(), Map :: map()) -> boolean().
recur([], Map) ->
  maps:size(Map) == 26;
recur([H | T], Map) ->
  case maps:is_key(H, Map) of
    true ->
      Val = maps:get(H, Map),
      Map1 = Map#{H => Val + 1},
      case maps:size(Map1) of
        26 ->
          true;
        _ ->
          recur(T, Map1)
      end;
    _ ->
      Map1 = Map#{H => 1},
      case maps:size(Map1) of
        26 ->
          true;
        _ ->
          recur(T, Map1)
      end
  end.
