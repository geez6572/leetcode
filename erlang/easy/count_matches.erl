-module(count_matches).

-spec count_matches(Items :: [[unicode:unicode_binary()]],
                    RuleKey :: unicode:unicode_binary(),
                    RuleValue :: unicode:unicode_binary()) ->
                     integer().
count_matches(Items, RuleKey, RuleValue) ->
  case RuleKey of
    <<"type">> ->
      calculate_count(Items, 1, RuleValue);
    <<"color">> ->
      calculate_count(Items, 2, RuleValue);
    _ ->
      calculate_count(Items, 3, RuleValue)
  end.

calculate_count([], _, _) ->
  0;
calculate_count([H | T], KeyIndex, RuleValue) ->
  Rest = calculate_count(T, KeyIndex, RuleValue),
  case lists:nth(KeyIndex, H) of
    RuleValue ->
      1 + Rest;
    _ ->
      Rest
  end.
