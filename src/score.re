type t = (int, int);

let increment = ((a, b), player) =>
  switch (player) {
  | Player.A => (a + 1, b)
  | Player.B => (a, b + 1)
  };

let print = ((a, b)) => a->string_of_int ++ " - " ++ b->string_of_int;

let of_round = round => {
  let acc = ref((0, 0));
  Array.map(
    winner => {
      let prev = acc^;
      acc := increment(prev, winner);
      acc^;
    },
    round,
  );
};