def nqueen(n):
    board = [["."] * n for i in range(n)]
    col = set()
    postivieDiag = set()
    negativeDiag = set()

    def backtrack(r):
        if (r == n):
            for i in board:
                print(i)
            print()

        for c in range(n):
            if (c in col or (r - c) in negativeDiag or (r + c) in postivieDiag):
                continue

            col.add(c)
            postivieDiag.add(r + c)
            negativeDiag.add(r - c)
            board[r][c] = 'Q'
            backtrack(r + 1)

            col.remove(c)
            postivieDiag.remove(r + c)
            negativeDiag.remove(r - c)
            board[r][c] = '.'

    backtrack(0)


inp = int(input("Enter the numer of queens : "))
nqueen(inp)