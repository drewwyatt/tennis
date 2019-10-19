type t =
  | A
  | B;
let of_char = c => c === 'A' ? A : B;