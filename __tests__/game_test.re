open Jest;

describe("Floop", () =>
  Expect.(test("hey", () =>
            expect(1 + 2) |> toBe(3)
          ))
);