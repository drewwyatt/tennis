let _big_string =
  Array.make(1000, "AB") |> Array.fold_left((a, b) => a ++ b, "AAABBB");

let _to_player_with_string = (str, i, _) =>
  str->String.get(i)->Player.of_char;

let strings = [|
  "AAAA",
  "BBBB",
  "AAABA",
  "AAABBBABBB",
  "BBBAAABAAA",
  _big_string ++ "BB",
|];

let parse =
  Array.map(str =>
    Array.make(str->String.length, ())
    |> Array.mapi(_to_player_with_string(str))
  );