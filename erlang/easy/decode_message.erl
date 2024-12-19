-module(decode_message).

-spec decode_message(Key :: unicode:unicode_binary(),
                     Message :: unicode:unicode_binary()) ->
                      unicode:unicode_binary().
decode_message(Key, Message) ->
  List = binary_to_list(Key),
  ConsMap = cons_map(List, #{}),
  Map = ConsMap#{$\s => $\s},
  MList = binary_to_list(Message),
  RsList = decode_message(MList, Map, []),
  list_to_binary(RsList).

decode_message([], _, Rs) ->
  Rs;
decode_message([H | T], Map, Rs) ->
  Ans = maps:get(H, Map),
  NewRs = Rs ++ [Ans],
  decode_message(T, Map, NewRs).

cons_map([], Map) ->
  Map;
cons_map([H | T], Map) ->
  case H of
    $\s ->
      cons_map(T, Map);
    _ ->
      case maps:is_key(H, Map) of
        true ->
          cons_map(T, Map);
        _ ->
          Cur = $a + maps:size(Map),
          NewMap = Map#{H => Cur},
          cons_map(T, NewMap)
      end
  end.
