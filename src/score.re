type t = (int, int);

let increment = (player, (a, b)) =>
  switch (player) {
  | Player.A => (a + 1, b)
  | Player.B => (a, b + 1)
  };

let of_round = round => Array.fold_right(increment, round, (0, 0));

let print = ((a, b)) => a->string_of_int ++ "-" ++ b->string_of_int;