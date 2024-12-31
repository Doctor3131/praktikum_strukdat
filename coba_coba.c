/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X) {
// kamus lokal
    bintree leftTemp;

// algoritma v1
    // if (!IsEmptyTree(*P)) {
    //     if (!SearchX(*P, X)) {
    //         leftTemp = left(*P);
    //         left(*P) = Tree(X, NIL, NIL);
    //         left(left(*P)) = leftTemp;
    //     } else {
    //         printf("\nterdapat %c pada tree\n", X);
    //     }
    // } else {
    //     akar(*P) = X;
    // }

// algoritma v2
    if (!IsEmptyTree(*P)) {
        if (!SearchX(*P, X)) {
            if (IsUnerRight(*P)) {
                left(*P) = Tree(X,NIL,NIL);
            } else if (IsUnerLeft(*P)) {
                right(*P) = Tree(X,NIL,NIL);
            } else {
                InsertX(&left(*P), X);
                if (!SearchX(*P, X)) {
                InsertX(&right(*P), X);
                }
            }
    } else {
        akar(*P) = X;
        }
    }
}

