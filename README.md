
# Chess P2P

The project is a P2P chess that supports multiplayer mode.

During the development it was used:  
  • QT 6  
  • C++ 17
  
    ![Alt text](https://s127vlx.storage.yandex.net/rdisk/462c9bb5b06c249b5a67c474b6335d1e8bdec0cdeb18e721061d9d35fb5a1174/6373d5e4/RQZ7fmHkyJ6IWJG0cs2ZYiC1um0jY_2w_XhqkVLoLOoI4IaN7jKP95ozschr6BM81G2UCbvYf5I5-fZlhO6HaA==?uid=733159442&filename=uml.jpg&disposition=inline&hash=&limit=0&content_type=image%2Fjpeg&owner_uid=733159442&fsize=95543&hid=66ce88fee3c85978884d0d0fdeb33263&media_type=image&tknv=v2&etag=b315584f4b6d520ee62e944d318a8333&rtoken=C0ocRrNGwynP&force_default=yes&ycrid=na-7c34da01b58422f4b6a0e497a1ad9a5d-downloader19e&ts=5ed8642764100&s=31361bd008af2b83a23f1bb67f8f18ccb91e4bd01831e525b50160bbe44a91a7&pb=U2FsdGVkX1-PTpkOUmGk7qzni_4sKi9SgYxqCZ1LEbXPfohZeENJqdVT8HVvun8nTH_xzLAH1P1XRmYC4fLYvfW-N3yXDsUKNr7vJGeeb9s "Board")

## Chess Board Description

Chess is played by two players on a chess board measuring eight-by-eight squares. The 64 squares alternate between light and dark colours - traditionally, black and white. When properly set up, a white square should be the rightmost square along the edge closest to each player.  
  
  ![Alt text](https://s54vlx.storage.yandex.net/rdisk/2b5feffabb448fbf324f4f684f54e8d61e49eff130a36f92daaf6cf80b4f4e6c/6373d22a/RQZ7fmHkyJ6IWJG0cs2ZYqMnLCC7GnY1huvdSY3PdZA6goQxezztzod6Ko3D0w6fDM3q46TH-ihc0kxh-ILiPg==?uid=733159442&filename=2022-11-15%2017.41.50.jpg&disposition=inline&hash=&limit=0&content_type=image%2Fjpeg&owner_uid=733159442&fsize=49678&hid=1db3819c42a8b3ec1c8dbc9638f99d22&media_type=image&tknv=v2&etag=b2a31cc095e4b95594ba0bbde3f4bfff&rtoken=W00Rd4cUQOJa&force_default=yes&ycrid=na-f88b3a54c4ee189416e415658854a8d1-downloader11e&ts=5ed8609995e80&s=7d948518516644c57fdf289d64665c1441f2a48771667e8c002fa598023e3131&pb=U2FsdGVkX1-HuV0PkFPzu9-vL19bzhW78NAZmCyIDN2OqbxiyES3YqEZpNdujuS7sR1d3uzr2l-vkCc-8EJaGVYDYzpxhppxS8ZOWz0PaRQ "Board")
  
Players’ pieces are set up in the two horizontal rows (known as ranks) closest to each player. The second rank - ie. the second row from the player’s perspective - consists of a line of eight pawns, each placed on a single square.
  
The closer rank is nearly symmetrical, with rooks (also known as castles) placed on the two leftmost and rightmost corner squares, followed by knights on the inside space next to them, then bishops.

The two central squares of the rank are occupied by the king and queen. The queen is placed on the square matching her colour (for example, the black queen on the black square), with the king occupying the remaining square of the opposite colour. This means that the king and queen of each colour face each other, making the correct setup symmetrical between the two players.

The white player takes the first move, with players alternating single turns until a player is defeated via checkmate or resigns. A draw can also be agreed. If playing with an optional timer, as in tournaments, the first player to run out of time forfeits the game.
## Basic Chess Rules

In chess, each player takes turns to make a single move. Players cannot choose to skip a turn - they must move a piece. Each chess piece moves in a specific way, and must be moved according to its legal movement.

![Alt text](https://s06vlx.storage.yandex.net/rdisk/8f8640afbb15e949be4b19486659f104f96252a505288f40cf32147a326dd1e0/6373d221/RQZ7fmHkyJ6IWJG0cs2ZYmmxqMPq8m2nvz8qsPSw37uOgwammoC-2haHUhydmTRW3Owd_b6TYyfF7xCN1CwClg==?uid=733159442&filename=2022-11-15%2017.41.44.jpg&disposition=inline&hash=&limit=0&content_type=image%2Fjpeg&owner_uid=733159442&fsize=49711&hid=59408cb3d45bff1563c24818c34ea65d&media_type=image&tknv=v2&etag=67e639b8b8ea97d34fbc88bf588a867c&rtoken=gNSfpTcevSwo&force_default=yes&ycrid=na-453d3022c0595af5238f0b95697ab3a1-downloader11e&ts=5ed8609100a40&s=287fac9cfd5bf2f683aa81b3d971bf95fa14b3b523ecbda3426d9f9507545324&pb=U2FsdGVkX1-yZMCtYiIEl20iwi90jFpGBmP9Xwf2e1e6yYl70PAKSeFjyxikfnELKRtK1Q3RzsSn_IuoBuZ9_q9ccCENNAcHiFJoeCyK53Q "Move")

Except for the knight, which may jump over pieces, pieces cannot move through pieces of either colour without either stopping (in the same of a piece of the same colour) or capturing them (in the case of a piece of the opposite colour).

How to capture pieces
If a piece lands on a space with an opponent’s piece, that piece is captured and removed from the board. Pieces cannot be placed on the same square as a piece of the same colour. When a piece captures an opponent’s piece, it must finish its current move action and end the player’s turn.
## Figures Movement Rules

#### Pawn

Pawns move one square forward in a straight line. They cannot move horizontally, diagonally or backwards.

An exception to this is if a pawn is yet to be moved during the game. If a pawn has not yet moved, it may be moved two squares forward as a single move. Both squares must be empty. The player can also choose to move the piece a single square.

The only time a pawn may move diagonally is when capturing an opponent’s piece. Pawns may capture an opponent’s piece on either of the diagonal spaces to the left or right ahead of the piece. As part of capturing the piece, the pawn will move diagonally to replace the captured piece. A pawn cannot capture an adjacent piece on any other square, or move diagonally without capturing.

#### Rook (Castle)

The rook, sometimes called the castle, can move any number of squares horizontally along its current row (rank) or column (file). It cannot pass through pieces of the same colour, and can capture pieces of the opposite colour by moving onto an occupied space. It cannot move diagonally for any reason.

#### Knight

Knights are the only chess piece that may be moved ‘through’ other pieces by ‘jumping’ over them. It captures pieces as normal by landing on a space occupied by a piece of the opposite colour and cannot move to a square occupied by a piece of the same colour, but may move over pieces of either colour during its move.

Knights move in a fixed ‘L’ pattern: two squares forward, backward, left or right, then one square horizontally or vertically, or vice versa - one square forward, backward, left or right, followed by two squares horizontally or vertically to complete the ‘L’ shape.

This means that the knight can always move to the closest square that is not on its current row (rank), column (file) or directly adjacent diagonally.

The knight must move the full distance - it cannot move just two squares in a straight line without also moving one to the side, for instance.

#### Bishop

The bishop can move any number of squares diagonally - this means it always moves along the diagonal line of squares matching the current colour of its square. This means that each player begins the game with one bishop that can move on each colour. A bishop cannot move horizontally or vertically for any reason. It cannot move through pieces of the same colour, and captures a piece of the opposite colour by moving onto its square.

#### Queen

The queen may move any number of squares horizontally, vertically or diagonally. These movements must be made in a single straight line during a single turn. (In other words, you can’t move three squares diagonally, followed by three spaces vertically.) The queen cannot move through pieces of the same colour, and captures a piece of the opposite colour by moving onto its square.

#### King

The king moves a single space horizontally, vertically or diagonally. The king cannot move into a space that would grant a check or checkmate to the opponent player.

As an exception to all other chess pieces, the king is never captured - a player loses the match when the king is placed into checkmate, which would lead to an unavoidable capture on the opponent’s next turn.
## What is check and checkmate?

When a piece moves in a way that would allow a player to capture the opponent’s king on their next turn, the attacking player typically announces “check”.

The player placed into check must move their king or move another piece to stop the attack on their next turn - either by blocking the move or capturing the attacking piece.

If a player creates a situation where their opponent cannot stop their king from being captured on the next turn, the attacking player announces “checkmate” and immediately wins the game. The king is never captured - a game of chess is won when a successful checkmate is announced.

![Alt text](https://s185vlx.storage.yandex.net/rdisk/49ddf696e719c6f2e5434e9d022f5a69ffe840d72ac8726f7bfb63dda2fa1da6/6373cfcb/RQZ7fmHkyJ6IWJG0cs2ZYlUvGXvwcSatcYOo0_EYHRLyK1NwAFcy-FbKL73p2o0O4Y5gXiJwLJTteLgc7PwDUg==?uid=733159442&filename=2022-11-15%2017.41.27.jpg&disposition=inline&hash=&limit=0&content_type=image%2Fjpeg&owner_uid=733159442&fsize=50651&hid=17fa3fcd6740fe051f85beb634c7c2d7&media_type=image&tknv=v2&etag=ad3054237ceecfc79f42c7eb051158b6&rtoken=vv9biSprTSoK&force_default=yes&ycrid=na-2fb74f7d298445768b30ce8142322a81-downloader7f&ts=5ed85e56b48c0&s=9fe29791e4c0b29e71b4795383d36997ccb292fa62b4b0fda8ec089a3c9b6d2e&pb=U2FsdGVkX1_4bwwbb65TKPzVtpKbzcp210klevquretbFU-83pbiFnBMDlXhiRBEYfWfHLBWQR-4azNR8tGANAzEFS4ecHCAXvHCgO-lmJg "Win")

A player can also choose to resign, granting their opponent the victory. Matches can also end in an agreed draw - for example, as the result of stalemate leaving a player without any legal moves, or if no player can win using available legal moves, a situation known as a “dead position”. One example of a dead position is when both players are left with their king as their only remaining piece on the board.

Draws can also occur as the result of advanced rules typically used in professional tournaments, including identical board positions occurring three or five times - rules known respectively as threefold repetition and fivefold repetition - or no captures or pawn moves taking place within the last 50 or 75 moves. The exact rules used can depend on the tournament and agreement between the players.


## Advanced Chess Rules

There are a number of advanced rules that can be used in chess, along with specific openings and board positions known by a variety of names, from the Double King's Pawn Opening to the famous King’s Gambit and Queen’s Gambit.

Advanced rules can include specific variants that alter the core rules of the game, along with surrounding requirements often used in tournament settings, such as timing and the touch-move rule - which states that once a piece is touched by a player, it must make a legal move.

As this is a beginner’s guide to learning chess, we’ll only be covering some of the essential advanced rules here - rules that should always be used in conjunction with the basic rules for moving and capturing pieces, as well as the standard setup and rules for declaring checkmate.

Once you know the basics of how to play chess, there are hundreds of books and other resources out there to help you discover the deep strategy and near-endless variations possible during games - as well as local tournaments that can help you refine your play and tactics.


### How to promote a pawn
If a pawn reaches the opposite edge of the board - the farthest row (rank) from the controlling player - it is promoted to another piece: a rook, knight, bishop or queen. The new piece replaces the pawn on its current square, and follows the movement rules for the respective piece.

While most casual players use captured pieces to represent promoted pieces, a pawn can legally be promoted to any piece regardless of whether it has been captured. For example, a player may have multiple queens as the result of promoting pawns, or multiple bishops able to move along diagonal lines of the same colour depending on the square on which the pawn was promoted.

There is no limit to the number of pawns that can be promoted.

### What is En passant?
En passant - French for ‘in passing’ - is one of the most famous moves in chess. En passant occurs when a pawn moves two squares forward as the result of its optional starting move.

If an opponent’s pawn would have been able to legally capture the moving pawn had it only moved one square instead of two, the opponent can declare en passant on their next turn and move their pawn diagonally onto the square that the pawn passed through - capturing the pawn as if it had only moved one square.

En passant must be declared and made as the opponent’s next turn to be legal - otherwise, the player with the chance to capture the pawn loses the opportunity.

### What is Castling?
Castling is perhaps the most complicated basic rule in chess, and a rule that many beginners often overlook as a result.

Castling is permitted when a player’s king piece and a rook have not yet moved during the game. Castling can be performed with either rook, as long as they haven’t moved - in other words, they are still in their starting corners on the edge closest to the controlling player.

Castling involves a player moving the king piece two squares towards the rook with which they are castling, before moving the rook to the square that the king moved ‘through’. This effectively puts the rook adjacent on the other side of the king, while the king moves two squares towards the space in which the rook started the game. Regardless of whether castling is performed with the rook closer to the king (kingside) or one square further away (queenside), the king only ever moves two spaces.

The king cannot be used in a castling manoeuvre if it is currently in check, but a rook can be used in castling even if it is under threat from an opponent’s piece - in other words, if it could be captured on the opponent’s next turn, or on any of the squares it passes through while performing the move.

As usual, castling cannot be used to move the king if it would put the king into check. Castling also cannot be used if there are any pieces between the king and the rook - the squares between must be clear.
## Gameplay Description

The chess program is intuitive and understandable for beginners.

When you click on a figure, the trajectory of its movement appears.
Each player has a visible analogous timer for counting the game time. The standard is 1 hour.

Each player can only control pieces of his own color, sequentially.

When one of the players runs out of time, a loss is automatically declared.

At the end of the game with any outcome, the players will see a screen informing them of their status, that is, whether the player has lost or won.
## Multiplayer Description

When you turn on the program, a game room is created, to which the next connecting player is automatically added.

After connecting, the first player sees a waiting screen.

![Alt text](https://s824sas.storage.yandex.net/rdisk/202cfef71bea70cdef753c5e12b04b248e6f462061cfa1c68635e715d2014b5b/6373d215/RQZ7fmHkyJ6IWJG0cs2ZYos05agDiWqjX3hxQ10VUZ_rJe3KGmf6et8vZ0csDZU6QOR5sze4CemOtqEAs9yIOg==?uid=733159442&filename=2022-11-15%2017.41.32.jpg&disposition=inline&hash=&limit=0&content_type=image%2Fjpeg&owner_uid=733159442&fsize=50398&hid=23a70405fdf52cc81b9bedfcd54a7b48&media_type=image&tknv=v2&etag=a90534e385d6e71afb379f97452313b4&rtoken=ZQODRIG86z5W&force_default=yes&ycrid=na-f9bfcc38509586c69e8f3dd002868bf7-downloader11e&ts=5ed860858ef40&s=9dee9c6c58e53e6468203006371341cc0a742ad7f540c88c3e5c5d694f5ce607&pb=U2FsdGVkX18HqECmypf5bW8uBhuGg4Yo3lDQIjQGGD63mjgMnYFbRS926fRm3Z790HuegTZDo5Bz8hrAwZO6Fh_cITEM_3dxC3HQP6kBLv4 "Wait for connection")

The move is transmitted sequentially, depending on whether you have connected to an existing room or a new one has been created for you. This simulates the randomness of the color selection.

The program supports the simultaneous connection of a large number of players.
