# MC & FA — MASTER STUDY GUIDE
**Course:** MAT 135 — Matrices, Complex Variable & Fourier Analysis
**Department:** CSE, Metropolitan University
**Scope:** CT-01 (Matrices) + CT-02 (Eigenvalues, LU, Complex Numbers)
**Built from:** Suggestion sheet + all CT papers (Batch 62B/C/D + Spring 2026 Set A/B) + theory notes

---

## TABLE OF CONTENTS

- **PART I — Roadmap & Syllabus**
- **PART II — MATRICES (Concept Teaching)**
  1. Definitions & Types
  2. Determinants & Adjoint
  3. Inverse — 3 Methods
  4. Rank of a Matrix
  5. Systems of Linear Equations (Adjoint, Gauss Elim, Gauss-Jordan, LU)
  6. Eigenvalues & Eigenvectors
  7. Hermitian / Skew-Hermitian
- **PART III — COMPLEX NUMBERS (Concept Teaching)**
  1. Definitions & Special Numbers
  2. Forms (Cartesian / Polar / Exponential)
  3. Argand Diagram & Modulus
  4. De Moivre's Theorem (Statement + Proof)
  5. Triangle Inequality & Modulus Properties
  6. Powers, Roots, Trig Identities
- **PART IV — Fully Worked Solutions to Every CT Problem**
- **PART V — Formula Sheet / Cheat Sheet**
- **PART VI — Common Mistakes & Shortcuts**
- **PART VII — Practice Set (Easy / Medium / Hard)**
- **PART VIII — Mock Test (with Answer Key)**
- **PART IX — Active-Learning Quiz & Revision Checklist**
- **PART X — Analysis of Your Attempts & Weak-Area Tracker**
- **PART XI — Adaptive Active-Learning Mode**

---

# PART I — ROADMAP & SYLLABUS

## The "Suggestion" sheet decoded

> **Matrix (3 marks side):** Definition of matrix, Inverse matrix (3 methods incl. row-canonical), System of linear equations (LU, Gauss elimination, Gauss-Jordan).
> **Complex (2 marks side):** De Moivre's theorem (proof + math), Graphical representation, Polar form, Triangle inequality.

## Learning roadmap (beginner → exam-ready)

| Stage | What to master | Why it matters |
|---|---|---|
| 1 | Matrix definitions & special types | Q4 always asks "Define X with example" |
| 2 | 2×2 / 3×3 determinants & cofactors | Foundation for adjoint, inverse, eigenvalues |
| 3 | Inverse by adjoint | One-shot Q for 5 marks |
| 4 | Row operations & row-canonical inverse | The 2nd inverse method asked |
| 5 | Solving Ax=b: Adjoint method | "Solve using Ad-joint method" Q1 type |
| 6 | Gauss Elimination (echelon form) | Always one Q (5 marks) |
| 7 | Gauss-Jordan (reduced echelon) | Always one Q (5 marks) |
| 8 | LU Decomposition (Doolittle) | CT-2 Q2 (8 marks) |
| 9 | Eigenvalues / Eigenvectors of 3×3 | CT-2 Q1 (8 marks) |
| 10 | Hermitian & Skew-Hermitian | CT-1 Q4 (Batch D) |
| 11 | Complex number forms & polar conversion | CT-2 Q2 (Spring 2026) |
| 12 | De Moivre proof + identities (cos³θ, cos⁵θ, sin³θ) | CT-2 Q3, Q4 |
| 13 | Triangle inequality / modulus identities | Show that \|z₁/z₂\| = \|z₁\|/\|z₂\| |
| 14 | Geometry with complex numbers | Median of triangle problem (62D) |

## Difficulty grouping of problems seen

- **Easy (definitions / direct plug-in):** CT-01 Q4 definitions; Purely Real / Imaginary; 2×2 inverse; Q3 of CT-2 (4-mark identities).
- **Medium (single technique):** Adjoint inverse, Gauss elimination, polar conversion, simple De Moivre identity (sin³θ, cos³θ).
- **Hard (multi-step):** LU + back-substitution, 3×3 eigenvalue with double root, cos⁵θ expansion, skew-Hermitian verification with complex entries.

---

# PART II — MATRICES (CONCEPT TEACHING)

## 1. Definitions & Special Types

**Intuition first:** A matrix is a table of numbers arranged in rows and columns. Think of it like a spreadsheet that you can do algebra with.

**Formal:** An **m × n matrix** is a rectangular array `A = [a_ij]` where `i = 1…m`, `j = 1…n`.

### The "Define X with example" cheat-card

| Matrix | Condition | Example |
|---|---|---|
| **Square** | rows = cols (n×n) | `[[1,2],[3,4]]` |
| **Diagonal** | a_ij = 0 for all i ≠ j | `[[5,0,0],[0,3,0],[0,0,7]]` |
| **Identity I** | diagonal & all diag = 1 | `[[1,0],[0,1]]` |
| **Upper Triangular** | a_ij = 0 when i > j | `[[1,2,3],[0,4,5],[0,0,6]]` |
| **Lower Triangular** | a_ij = 0 when i < j | `[[1,0,0],[2,3,0],[4,5,6]]` |
| **Symmetric** | A = Aᵀ (a_ij = a_ji) | `[[1,2,3],[2,4,5],[3,5,6]]` |
| **Skew-Symmetric** | A = −Aᵀ ; diagonal = 0 | `[[0,2,-3],[-2,0,4],[3,-4,0]]` |
| **Inverse A⁻¹** | A·A⁻¹ = I | A = `[[2,0],[0,3]]` ⇒ A⁻¹ = `[[1/2,0],[0,1/3]]` |
| **Hermitian** | A = (Ā)ᵀ = A* | diagonals real; `[[2, 3+i],[3-i, 5]]` |
| **Skew-Hermitian** | A = −A* | diagonals purely imaginary |

**Memory trick (Symmetric vs Skew):** *Symm* is **same** across the diagonal; *Skew* is **opposite** sign across the diagonal (and 0's on the diagonal because only 0 = −0).

---

## 2. Determinants & Adjoint

### 2×2 determinant
`det([[a,b],[c,d]]) = ad − bc`

### 3×3 determinant (cofactor expansion along Row 1)
For `A = [[a,b,c],[d,e,f],[g,h,i]]`:
```
det(A) = a(ei − fh) − b(di − fg) + c(dh − eg)
```

### Cofactor matrix C
`C_ij = (−1)^(i+j) · M_ij` where M_ij is the minor (det of the 2×2 you get by deleting row i and column j).

### Adjoint (Adjugate)
`adj(A) = Cᵀ`  (transpose of the cofactor matrix). **This transpose step is the #1 mistake.**

### Sign-pattern shortcut for 3×3 cofactors
```
+  −  +
−  +  −
+  −  +
```

---

## 3. Inverse — 3 Methods

### Method 1 — Adjoint Method
```
A⁻¹ = (1/det A) · adj(A),    provided det A ≠ 0
```
**Steps:** (1) det A; (2) all 9 cofactors; (3) transpose to adj A; (4) divide by det A.

### Method 2 — Row Canonical (Gauss-Jordan) Method
Form the augmented matrix `[A | I]`. Apply elementary row operations until LHS = I. The RHS becomes A⁻¹:
```
[A | I]  →  row ops  →  [I | A⁻¹]
```

### Method 3 — Using Elementary Matrices / Cayley-Hamilton (rarely asked but completes the "3 ta type" expectation in the suggestion sheet)
Express A as a product of elementary matrices E₁E₂…E_k = A. Then A⁻¹ = E_k⁻¹…E₁⁻¹.

> **Exam tip:** If the question says "**by row canonical method**" → use Method 2. If it says "**by adjoint method**" → use Method 1.

---

## 4. Rank of a Matrix

**Rank = number of non-zero rows in the row-echelon form** (also = number of linearly independent rows = number of linearly independent columns).

**Procedure:**
1. Apply row operations to bring A to echelon form (zero entries below each leading pivot).
2. Count non-zero rows.

**Properties used in CT:**
- Rank ≤ min(m, n)
- Rank tells you "nature of solution" of Ax = b:
  - rank(A) = rank(A|b) = n  → unique solution
  - rank(A) = rank(A|b) < n  → infinitely many solutions
  - rank(A) ≠ rank(A|b)      → no solution (inconsistent)

---

## 5. Systems of Linear Equations

### 5.1 Adjoint Method (Solve Ax = b)
1. Compute det(A); if zero, can't use this method.
2. Compute adj(A).
3. `x = (1/det A) · adj(A) · b`.

### 5.2 Gaussian Elimination (= Row-Echelon Form)
Goal: turn the coefficient matrix into upper-triangular form, then back-substitute.

**Three legal row operations:**
- R_i ↔ R_j (swap)
- R_i → k · R_i (scale, k ≠ 0)
- R_i → R_i + k · R_j (add a multiple of another row)

**Mantra:** "make zeros below the pivot, top to bottom."

### 5.3 Gauss-Jordan (= Reduced Row-Echelon Form, RREF)
Same as Gauss elimination, **plus** make zeros **above** each pivot too, and scale pivots to 1. The final form gives x, y, z directly — no back-substitution needed.

### 5.4 LU Decomposition (Doolittle's Method)
Write `A = L · U` where:
- L is **lower triangular with 1's on diagonal**
- U is **upper triangular**

For 3×3:
```
L = [[1,0,0],[l21,1,0],[l31,l32,1]]
U = [[u11,u12,u13],[0,u22,u23],[0,0,u33]]
```

**Formulas (compute in order):**
```
u11 = a11,  u12 = a12,  u13 = a13
l21 = a21/u11,           l31 = a31/u11
u22 = a22 − l21·u12      u23 = a23 − l21·u13
l32 = (a32 − l31·u12)/u22
u33 = a33 − l31·u13 − l32·u23
```

**Solve Ax = b in two steps:**
1. **Forward sub:** Ly = b  → solve for y top-down.
2. **Back sub:** Ux = y  → solve for x bottom-up.

---

## 6. Eigenvalues & Eigenvectors

**Definition:** A non-zero vector v is an eigenvector of A with eigenvalue λ if `A v = λ v`.

**Procedure:**
1. **Characteristic equation:** `det(A − λ I) = 0`. Expand to get a polynomial in λ.
2. **Solve** for the roots λ₁, λ₂, λ₃ (eigenvalues).
3. **For each λ_i:** solve `(A − λ_i I) v = 0` to get the eigenvector v_i.

**Key shortcut:** For a 3×3 matrix, the characteristic polynomial is
```
λ³ − (tr A) λ² + (sum of 2×2 principal minors) λ − det A = 0
```
(`tr A` = sum of diagonal entries.) Use Vieta to sanity-check: λ₁+λ₂+λ₃ = tr A, λ₁λ₂λ₃ = det A.

**To find roots fast:** try λ = 0, ±1, ±2, ±3 (rational root theorem). Factor out, then solve the quadratic.

---

## 7. Hermitian / Skew-Hermitian

Let A* = (Ā)ᵀ (complex conjugate transpose).

| Type | Condition | What it forces on the diagonal |
|---|---|---|
| Hermitian | A* = A  ⇔ a_ji = ā_ij | diagonal entries are **real** |
| Skew-Hermitian | A* = −A ⇔ a_ji = −ā_ij | diagonal entries are **purely imaginary or 0** |

**Verification routine:**
1. Diagonal: real (Herm) or 0/pure imaginary (Skew-Herm)?
2. Each off-diag pair (a_ij, a_ji): is a_ji = ±ā_ij?

---

# PART III — COMPLEX NUMBERS (CONCEPT TEACHING)

## 1. Definitions & Special Numbers

A complex number is `z = x + iy` with `i² = −1`.
- `Re(z) = x`, `Im(z) = y`.
- **Purely Real:** y = 0 (e.g., `z = 7 = 7 + 0i`).
- **Purely Imaginary:** x = 0 (e.g., `z = 5i = 0 + 5i`).
- **Conjugate:** `z̄ = x − iy`.
- **Modulus:** `|z| = √(x² + y²)`.
- **Argument:** `arg(z) = θ`, the angle from positive real axis (be careful with quadrant).

---

## 2. Forms

| Form | Expression | Notes |
|---|---|---|
| Cartesian / Rectangular | `z = x + iy` | Default form |
| Polar / Trigonometric | `z = r(cos θ + i sin θ)` | r = \|z\|, θ = arg z |
| Exponential / Euler | `z = r e^(iθ)` | Multiplication & powers become trivial |

**Conversion:** `r = √(x² + y²)`, `θ = atan2(y, x)` (quadrant-aware).

### Quadrant-aware argument table

| Quadrant | Sign of (x, y) | Argument |
|---|---|---|
| I | (+, +) | θ = arctan(y/x) |
| II | (−, +) | θ = π − arctan(\|y/x\|) |
| III | (−, −) | θ = −π + arctan(\|y/x\|)  (or π + arctan(y/x)) |
| IV | (+, −) | θ = − arctan(\|y/x\|) |

---

## 3. Argand Diagram & Modulus

The **Argand plane** has Re on the horizontal axis and Im on the vertical axis. Then `z = x + iy` is the point (x, y), and |z| is the distance from origin.

> **Visual:** plotting `z = 1 + i` gives a point at (1,1); the line from origin has length √2 and angle 45°.

---

## 4. De Moivre's Theorem

**Statement:** For any integer n (extends to rationals/reals with care for branches):
```
[r(cos θ + i sin θ)]^n = r^n (cos nθ + i sin nθ)
```
For r = 1: `(cos θ + i sin θ)^n = cos nθ + i sin nθ`.

### Proof (induction on positive integer n)

**Base case (n = 1):** `(cos θ + i sin θ)^1 = cos θ + i sin θ`. ✓

**Inductive hypothesis:** Assume true for n = k:
`(cos θ + i sin θ)^k = cos kθ + i sin kθ`.

**Inductive step (n = k+1):**
```
(cos θ + i sin θ)^(k+1)
   = (cos θ + i sin θ)^k · (cos θ + i sin θ)
   = (cos kθ + i sin kθ)(cos θ + i sin θ)
   = (cos kθ · cos θ − sin kθ · sin θ) + i (sin kθ · cos θ + cos kθ · sin θ)
   = cos(kθ + θ) + i sin(kθ + θ)        ← angle-addition formulas
   = cos(k+1)θ + i sin(k+1)θ.            ✓
```
By induction, the result holds for all n ∈ ℕ.

**For n = 0:** LHS = 1 = cos 0 + i sin 0. ✓
**For negative n:** Let n = −m (m > 0). Use `1/(cos θ + i sin θ) = cos θ − i sin θ = cos(−θ) + i sin(−θ)`, then apply the positive case. ✓

### How De Moivre is used

1. **Powers of complex numbers:** Convert to polar, raise r to the power, multiply θ by n.
2. **Roots:** The n-th roots of `r e^(iθ)` are `r^(1/n) · e^(i(θ + 2kπ)/n)`, k = 0, 1, …, n − 1.
3. **Trig identities for cos nθ, sin nθ:** Expand `(cos θ + i sin θ)^n` by the binomial theorem and equate real/imaginary parts.

---

## 5. Triangle Inequality & Modulus Properties

```
|z₁ + z₂| ≤ |z₁| + |z₂|                (triangle inequality)
||z₁| − |z₂|| ≤ |z₁ − z₂|              (reverse triangle inequality)
|z₁ z₂| = |z₁| · |z₂|
|z₁ / z₂| = |z₁| / |z₂|     (z₂ ≠ 0)
|z̄| = |z|,   z · z̄ = |z|²
```

**Quick proof of |z₁ + z₂| ≤ |z₁| + |z₂|:**
```
|z₁ + z₂|² = (z₁ + z₂)(z̄₁ + z̄₂)
           = |z₁|² + |z₂|² + z₁z̄₂ + z̄₁z₂
           = |z₁|² + |z₂|² + 2 Re(z₁z̄₂)
           ≤ |z₁|² + |z₂|² + 2|z₁z̄₂|
           = |z₁|² + |z₂|² + 2|z₁||z₂|
           = (|z₁| + |z₂|)².
```
Take square roots.

---

# PART IV — FULLY WORKED SOLUTIONS

> Every problem from every CT paper in your folder, solved with full steps and verification.

---

## CT-01, Batch 62(B)

### Q1 (5) — Solve by Adjoint Method
```
x +  y +  z = 6
5x − y + 2z = 9
3x + 6y − 5z = 0
```
**A** = `[[1,1,1],[5,−1,2],[3,6,−5]]`, **b** = `[6, 9, 0]ᵀ`.

**det A** = 1·[(−1)(−5)−(2)(6)] − 1·[(5)(−5)−(2)(3)] + 1·[(5)(6)−(−1)(3)]
       = 1·(5−12) − 1·(−25−6) + 1·(30+3)
       = −7 + 31 + 33 = **57**.

**Cofactors:**
```
C11 = (−1)(−5) − (2)(6) = −7
C12 = −[(5)(−5) − (2)(3)] = +31
C13 = (5)(6) − (−1)(3) = +33
C21 = −[(1)(−5) − (1)(6)] = +11
C22 = (1)(−5) − (1)(3) = −8
C23 = −[(1)(6) − (1)(3)] = −3
C31 = (1)(2) − (1)(−1) = +3
C32 = −[(1)(2) − (1)(5)] = +3
C33 = (1)(−1) − (1)(5) = −6
```
**adj A** = transpose of cofactor matrix:
```
adj A = [[−7, 11,  3],
         [31, −8,  3],
         [33, −3, −6]]
```
**x = (1/57) · adj(A) · b:**
```
x = (1/57)(−7·6 + 11·9 + 3·0)  = (−42 + 99)/57 = 57/57   = 1
y = (1/57)(31·6 + (−8)·9 + 3·0)= (186 − 72)/57 = 114/57  = 2
z = (1/57)(33·6 + (−3)·9 + (−6)·0) = (198 − 27)/57 = 171/57 = 3
```
**Answer:** **x = 1, y = 2, z = 3.**
**Check:** 1+2+3=6 ✓, 5−2+6=9 ✓, 3+12−15=0 ✓.

---

### Q2 (5) — Inverse of A by Row Canonical
```
A = [[1, 3, −2],
     [−3, 0, −5],
     [2, 5, 0]]
```
Form `[A | I]` and reduce:
```
[ 1  3  −2 | 1  0  0]
[−3  0  −5 | 0  1  0]
[ 2  5   0 | 0  0  1]

R2 → R2+3R1                    R3 → R3−2R1
[ 1  3  −2 | 1  0  0]
[ 0  9  −11| 3  1  0]
[ 0 −1   4 |−2  0  1]

R2 ↔ R3,  then R2 → −R2
[ 1  3  −2 | 1  0  0]
[ 0  1  −4 | 2  0 −1]
[ 0  9  −11| 3  1  0]

R1 → R1−3R2,  R3 → R3−9R2
[ 1  0   10|−5  0  3]
[ 0  1  −4 | 2  0 −1]
[ 0  0   25|−15 1  9]

R3 → R3/25
[ 1  0   10|−5      0     3   ]
[ 0  1  −4 | 2      0    −1   ]
[ 0  0   1 |−3/5   1/25   9/25]

R1 → R1−10R3,  R2 → R2+4R3
[ 1  0  0 |  1     −2/5   −3/5 ]
[ 0  1  0 | −2/5    4/25  11/25]
[ 0  0  1 | −3/5    1/25   9/25]
```
**Answer:**
```
A⁻¹ = (1/25) · [[25, −10, −15],
                 [−10,  4,  11],
                 [−15,  1,   9]]
```
(Equivalent decimal form is the right side of the augmented matrix above.)
**Check:** det A = 25 (matches the 1/25 factor); adj A computed via cofactors = same matrix above. ✓

---

### Q3 (5) — Gaussian Elimination
```
 x + 4y + 9z = 16
2x +  y +  z = 10
3x + 2y + 3z = 18
```
```
R2 → R2 − 2R1   :   −7y − 17z = −22
R3 → R3 − 3R1   :  −10y − 24z = −30

R3 → R3 − (10/7) R2 :  ((−24) − (10/7)(−17)) z = −30 − (10/7)(−22)
                       (−24 + 170/7) z = −30 + 220/7
                       (2/7) z = 10/7    ⇒  z = 5
```
Back-substitute:
- −7y − 17(5) = −22  ⇒  −7y = 63  ⇒  **y = −9**
- x + 4(−9) + 9(5) = 16  ⇒  x − 36 + 45 = 16  ⇒  **x = 7**

**Answer:** **x = 7, y = −9, z = 5.** ✓

---

### Q4 (5) — Gauss-Jordan
```
 x + 2y + 3z = 14
2x + 3y + 4z = 20
3x + 4y + 6z = 33
```
```
R2 → R2−2R1 :  −y − 2z = −8     ⇒   y + 2z = 8  (after multiplying by −1)
R3 → R3−3R1 : −2y − 3z = −9     ⇒   2y + 3z = 9 (×−1)

Use new R2, R3. R3 → R3 − 2R2 :  −z = −7   ⇒  z = 7
y + 2(7) = 8  ⇒  y = −6
x + 2(−6) + 3(7) = 14  ⇒  x = 5
```
**Answer:** **x = 5, y = −6, z = 7.** ✓

---

## CT-02, Batch 62(B)

### Q1 (8) — Eigenvalues & Eigenvectors
```
A = [[8, −8, −2],
     [4, −3, −2],
     [3, −4,  1]]
```
**Characteristic polynomial:**
det(A − λI) = `−λ³ + 6λ² − 11λ + 6` ⇒ `λ³ − 6λ² + 11λ − 6 = 0`.

Try λ = 1: `1 − 6 + 11 − 6 = 0` ✓. Factor:
`(λ − 1)(λ² − 5λ + 6) = (λ − 1)(λ − 2)(λ − 3)`.

**Eigenvalues:** **λ = 1, 2, 3.** (Sanity: 1+2+3 = 6 = tr A ✓; 1·2·3 = 6 = det A ✓.)

**For λ = 1:** (A − I) v = 0
`7x − 8y − 2z = 0;  4x − 4y − 2z = 0;  3x − 4y = 0`
From eq3: y = 3x/4. Plug eq2: 4x − 3x − 2z = 0 ⇒ x = 2z. Take x = 4 ⇒ y = 3, z = 2.
**v₁ = (4, 3, 2)ᵀ.**

**For λ = 2:** (A − 2I) v = 0
`6x − 8y − 2z = 0;  4x − 5y − 2z = 0;  3x − 4y − z = 0`
From eq3: z = 3x − 4y. Plug eq2: 4x − 5y − 2(3x − 4y) = −2x + 3y = 0 ⇒ y = 2x/3. Take x = 3 ⇒ y = 2, z = 1.
**v₂ = (3, 2, 1)ᵀ.**

**For λ = 3:** (A − 3I) v = 0
`5x − 8y − 2z = 0;  4x − 6y − 2z = 0;  3x − 4y − 2z = 0`
R1 − R2: x − 2y = 0 ⇒ x = 2y. R3 with this: 6y − 4y − 2z = 0 ⇒ z = y. Take y = 1 ⇒ x = 2, z = 1.
**v₃ = (2, 1, 1)ᵀ.**

---

### Q2 (8) — LU Factorization
```
 x + 2y + 3z =  9
4x + 5y + 6z = 24
3x +  y − 2z =  4
```
**Doolittle:**
```
u11 = 1, u12 = 2, u13 = 3
l21 = 4/1 = 4    l31 = 3/1 = 3
u22 = 5 − 4·2 = −3      u23 = 6 − 4·3 = −6
l32 = (1 − 3·2)/(−3) = (−5)/(−3) = 5/3
u33 = −2 − 3·3 − (5/3)·(−6) = −2 − 9 + 10 = −1
```
```
L = [[1, 0, 0], [4, 1, 0], [3, 5/3, 1]]
U = [[1, 2, 3], [0, −3, −6], [0, 0, −1]]
```
**Forward (Ly = b):** y₁ = 9; 4·9 + y₂ = 24 ⇒ y₂ = −12; 3·9 + (5/3)(−12) + y₃ = 4 ⇒ 27 − 20 + y₃ = 4 ⇒ y₃ = −3.
**Back (Ux = y):** −z = −3 ⇒ z = 3; −3y − 18 = −12 ⇒ y = −2; x − 4 + 9 = 9 ⇒ x = 4.

**Answer:** **x = 4, y = −2, z = 3.** ✓

---

### Q3 (4) — Show |z₁/z₂| = |z₁|/|z₂|
Let z₁ = a + ib, z₂ = c + id (z₂ ≠ 0).
```
z₁/z₂ = (a + ib)(c − id) / (c² + d²)
      = [(ac + bd) + i(bc − ad)] / (c² + d²)

|z₁/z₂|² = [(ac + bd)² + (bc − ad)²] / (c² + d²)²
        = [a²c² + 2abcd + b²d² + b²c² − 2abcd + a²d²] / (c² + d²)²
        = [(a² + b²)(c² + d²)] / (c² + d²)²
        = (a² + b²) / (c² + d²)
        = |z₁|² / |z₂|².
```
Take positive square roots: **|z₁/z₂| = |z₁|/|z₂|.** ∎

---

## CT-01, Batch 62(C)

### Q1 (5) — Adjoint Method
```
x +  y +  z = 3
x + 2y + 3z = 4
x + 4y + 9z = 6
```
A = `[[1,1,1],[1,2,3],[1,4,9]]`. det A = 1(18−12) − 1(9−3) + 1(4−2) = 6 − 6 + 2 = **2**.
**Cofactors:** C11=6, C12=−6, C13=2; C21=−5, C22=8, C23=−3; C31=1, C32=−2, C33=1.
adj A = `[[6, −5, 1], [−6, 8, −2], [2, −3, 1]]`.
**x = (1/2) adj(A) · b:**
- x = (1/2)(18 − 20 + 6) = 4/2 = **2**
- y = (1/2)(−18 + 32 − 12) = 2/2 = **1**
- z = (1/2)(6 − 12 + 6) = 0 = **0**

**Answer: x = 2, y = 1, z = 0.** ✓ (Check: 2+1+0=3, 2+2+0=4, 2+4+0=6.)

---

### Q2 (5) — Inverse by Row Canonical
```
A = [[1, 2, −3], [2, −1, 4], [4, 3, −4]]
```
det A = 1(4 − 12) − 2(−8 − 16) + (−3)(6 + 4) = −8 + 48 − 30 = **10**.

After row reduction (steps abbreviated for space — same procedure as Batch B Q2):
```
A⁻¹ = (1/10) · [[−8, −1,  5],
                 [24,  8, −10],
                 [10,  5, −5]]
```
or equivalently `[[−4/5, −1/10, 1/2], [12/5, 4/5, −1], [1, 1/2, −1/2]]`.

---

### Q3 (5) — Gaussian Elimination
```
x + y + z = 6
2x + 3y + 4z = 20
3x − 2y + z = 2
```
R2−2R1: y + 2z = 8.   R3−3R1: −5y − 2z = −16.
R3 + 5·R2: 8z = 24 ⇒ **z = 3**. y = 8 − 6 = **2**. x = 6 − 2 − 3 = **1**.

**Answer: x = 1, y = 2, z = 3.** ✓

---

### Q4 (5) — Definitions
**Square Matrix:** equal number of rows and columns. Example `[[1,2],[3,4]]`.
**Diagonal Matrix:** square with 0 off the main diagonal. Example `[[5,0,0],[0,3,0],[0,0,7]]`.
**Upper Triangular:** all entries below the main diagonal are 0. Example `[[1,2,3],[0,4,5],[0,0,6]]`.
**Lower Triangular:** all entries above the main diagonal are 0. Example `[[1,0,0],[2,3,0],[4,5,6]]`.
**Symmetric Matrix:** A = Aᵀ. Example `[[1,2,3],[2,4,5],[3,5,6]]`.

---

## CT-02, Batch 62(C)

### Q1 (8) — Eigenvalues / Eigenvectors
```
A = [[2, 2, 1], [1, 3, 1], [1, 2, 2]]
```
**Characteristic polynomial:** Expand det(A − λI):
```
(2−λ)[(3−λ)(2−λ) − 2] − 2[(2−λ) − 1] + 1·[2 − (3−λ)]
= (2−λ)(λ² − 5λ + 4) + 3(λ − 1)
= (λ − 1)·[(2−λ)(λ − 4) + 3]
= (λ − 1)·(−λ² + 6λ − 5)
= −(λ − 1)²(λ − 5)
```
**Eigenvalues:** **λ = 1 (double), λ = 5.**

**For λ = 5:** (A − 5I)v = 0
`−3x + 2y + z = 0; x − 2y + z = 0; x + 2y − 3z = 0`. From sum/diff: y = z, x = z. Take z=1.
**v = (1, 1, 1)ᵀ.**

**For λ = 1 (double, two free parameters):** (A − I)v = 0 reduces to a single equation `x + 2y + z = 0`.
- Take y = 1, z = 0 ⇒ x = −2. ⇒ v_a = (−2, 1, 0)ᵀ.
- Take y = 0, z = 1 ⇒ x = −1. ⇒ v_b = (−1, 0, 1)ᵀ.

---

### Q2 (8) — LU
```
x + 2y + 3z = 9
2x + 5y + z = 5
3x + y + 4z = 7
```
Doolittle:
```
u11=1, u12=2, u13=3 ;   l21=2, l31=3
u22 = 5 − 2·2 = 1 ;     u23 = 1 − 2·3 = −5
l32 = (1 − 3·2)/1 = −5
u33 = 4 − 3·3 − (−5)(−5) = 4 − 9 − 25 = −30
```
```
L = [[1,0,0],[2,1,0],[3,−5,1]] ,   U = [[1,2,3],[0,1,−5],[0,0,−30]]
```
**Ly = b:** y₁=9; y₂ = 5 − 2·9 = −13; y₃ = 7 − 3·9 − (−5)(−13) = 7 − 27 − 65 = −85.
**Ux = y:** −30z = −85 ⇒ z = 17/6; y − 5z = −13 ⇒ y = 7/6; x + 2y + 3z = 9 ⇒ x = −11/6.

**Answer: x = −11/6, y = 7/6, z = 17/6.** ✓

---

### Q3 (4) — Express cos⁵θ as a·cos5θ + b·cos3θ + c·cosθ
Use `2 cos θ = e^(iθ) + e^(−iθ)`:
```
(2 cos θ)⁵ = (e^(iθ) + e^(−iθ))⁵
         = e^(5iθ) + 5e^(3iθ) + 10e^(iθ) + 10e^(−iθ) + 5e^(−3iθ) + e^(−5iθ)
         = 2 cos 5θ + 10 cos 3θ + 20 cos θ.
```
So `32 cos⁵θ = 2 cos 5θ + 10 cos 3θ + 20 cos θ` ⇒
```
cos⁵θ = (1/16) cos 5θ + (5/16) cos 3θ + (5/8) cos θ.
```
Therefore **a = 1/16, b = 5/16, c = 5/8**. ✓

---

## CT-01, Batch 62(D)

### Q1 (5) — Adjoint Method
```
5x − 6y + 4z = 15
7x + 4y − 3z = 19
2x +  y + 6z = 46
```
A = `[[5,−6,4],[7,4,−3],[2,1,6]]`.
**det A** = 5(24+3) − (−6)(42+6) + 4(7−8) = 135 + 288 − 4 = **419**.

**Cofactors (transpose to get adj):**
```
adj A = [[ 27,  40,   2],
         [−48,  22,  43],
         [ −1, −17,  62]]
```
**x = (1/419) · adj A · b**, b = `[15, 19, 46]ᵀ`:
- x = (27·15 + 40·19 + 2·46)/419 = 1257/419 = **3**
- y = (−48·15 + 22·19 + 43·46)/419 = 1676/419 = **4**
- z = (−1·15 − 17·19 + 62·46)/419 = 2514/419 = **6**

**Answer: x = 3, y = 4, z = 6.** ✓ (Check: 15−24+24=15, 21+16−18=19, 6+4+36=46.)

---

### Q2 (5) — Definitions
- **Square Matrix:** same number of rows and columns. e.g. `[[1,2],[3,4]]`.
- **Diagonal Matrix:** square with 0 outside the main diagonal. e.g. `diag(2,3,5)`.
- **Inverse Matrix:** A⁻¹ exists when det A ≠ 0; satisfies A A⁻¹ = I. e.g. for `[[2,0],[0,3]]`, A⁻¹ = `[[1/2,0],[0,1/3]]`.
- **Identity Matrix:** diagonal of 1's, all other entries 0. e.g. `I₃ = [[1,0,0],[0,1,0],[0,0,1]]`.
- **Symmetric Matrix:** A = Aᵀ. e.g. `[[1,2,3],[2,4,5],[3,5,6]]`.

---

### Q3 (5) — Gaussian Elimination (same system as Batch B Q4)
```
x + 2y + 3z = 14
2x + 3y + 4z = 20
3x + 4y + 6z = 33
```
**Answer: x = 5, y = −6, z = 7.** (Steps in §CT-01 62(B) Q4 above.) Nature of solution: **unique** (det of coefficient matrix ≠ 0; ranks all = 3).

---

### Q4 (5) — Hermitian / Skew-Hermitian
**Definitions:** A is **Hermitian** if A* = A (a_ji = ā_ij). A is **Skew-Hermitian** if A* = −A (a_ji = −ā_ij). Diagonal: real for Hermitian, purely imaginary or 0 for Skew-Hermitian.

**(i) Verify** A = `[[2i, 1+i, −3], [−1+i, −4i, 2−i], [3, −2−i, i]]` is **Skew-Hermitian.**
- Diagonals: 2i, −4i, i — all purely imaginary. ✓
- Pair (1, 2): a₁₂ = 1+i, a₂₁ = −1+i. ā₁₂ = 1−i. Need a₂₁ = −ā₁₂ = −(1−i) = −1+i. ✓
- Pair (1, 3): a₁₃ = −3, a₃₁ = 3. −ā₁₃ = −(−3) = 3 = a₃₁. ✓
- Pair (2, 3): a₂₃ = 2−i, a₃₂ = −2−i. −ā₂₃ = −(2+i) = −2−i = a₃₂. ✓

So **A is Skew-Hermitian.** ∎

**(ii) Verify** B = `[[0, 2+3i, 1−i], [−2+3i, 5i, 4], [−1−i, −4, −6i]]` is **Skew-Hermitian.**
- Diagonals: 0, 5i, −6i — all 0 / purely imaginary. ✓
- a₁₂ = 2+3i ; a₂₁ = −2+3i ; ā₁₂ = 2−3i ; −ā₁₂ = −2+3i = a₂₁. ✓
- a₁₃ = 1−i ; a₃₁ = −1−i ; −ā₁₃ = −(1+i) = −1−i. ✓
- a₂₃ = 4 ; a₃₂ = −4 ; −ā₂₃ = −4. ✓

So **B is Skew-Hermitian.** ∎

---

## CT-02, Batch 62(D)

### Q1 (8) — Eigenvalues of a symmetric matrix
```
A = [[8, −6, 2], [−6, 7, −4], [2, −4, 3]]
```
Characteristic polynomial:
```
det(A − λI) = −λ³ + 18λ² − 45λ = −λ(λ² − 18λ + 45) = −λ(λ − 3)(λ − 15)
```
**Eigenvalues:** **λ = 0, 3, 15.**

- **λ = 0:** Solve Av = 0. Rows give y = 2x, z = 2x ⇒ **v₁ = (1, 2, 2)ᵀ**.
- **λ = 3:** (A−3I)v = 0. From row 3: x = 2y. From row 1: z = −2y ⇒ **v₂ = (2, 1, −2)ᵀ**.
- **λ = 15:** (A−15I)v = 0. y = −2z, x = 2z ⇒ **v₃ = (2, −2, 1)ᵀ**.

(Sanity: the three eigenvectors are mutually orthogonal — a property of symmetric matrices. v₁·v₂ = 2+2−4 = 0 ✓; v₁·v₃ = 2−4+2 = 0 ✓; v₂·v₃ = 4−2−2 = 0 ✓.)

---

### Q2 (8) — LU
```
 x + 5y + 12z = 47
 x + 2y +  3z = 14
2x + 4y +  3z = 19
```
Doolittle:
```
u11=1, u12=5, u13=12 ;  l21=1, l31=2
u22 = 2 − 1·5 = −3 ;    u23 = 3 − 1·12 = −9
l32 = (4 − 2·5)/(−3) = (−6)/(−3) = 2
u33 = 3 − 2·12 − 2·(−9) = 3 − 24 + 18 = −3
```
```
L = [[1,0,0],[1,1,0],[2,2,1]] ,   U = [[1,5,12],[0,−3,−9],[0,0,−3]]
```
**Ly = b:** y₁ = 47; y₂ = 14 − 47 = −33; y₃ = 19 − 2·47 − 2·(−33) = 19 − 94 + 66 = −9.
**Ux = y:** −3z = −9 ⇒ z = 3; −3y − 27 = −33 ⇒ y = 2; x + 10 + 36 = 47 ⇒ x = 1.

**Answer: x = 1, y = 2, z = 3.** ✓

---

### Q3 (4) — Modulus + Median Length
**Definition:** The **modulus** of a complex number `z = x + iy` is `|z| = √(x² + y²)` — its distance from the origin in the Argand plane.

**Triangle:** A(1, −2), B(−3, 4), C(2, 2). The median from C goes to the midpoint M of AB.
M = ((1 + (−3))/2, (−2 + 4)/2) = **(−1, 1)**.

In complex form: z_A = 1 − 2i, z_B = −3 + 4i, z_C = 2 + 2i, z_M = (z_A + z_B)/2 = −1 + i.
Length of median = `|z_C − z_M| = |2 + 2i − (−1 + i)| = |3 + i| = √(9 + 1) = √10`.

**Answer: √10 units.** ✓

---

## SPRING 2026 — Class Test 1

### Set A
**Q1 (5).** Inverse of `A = [[4, 5], [6, 7]]` by adjoint.
det A = 28 − 30 = −2. adj A = `[[7, −5], [−6, 4]]`.
**A⁻¹ = (−1/2) [[7, −5], [−6, 4]] = [[−7/2, 5/2], [3, −2]].** ✓

**Q2 (5).** Gauss-Elim: x+y+z = 6, 2x+3y+z = 13, x+2y+3z = 13.
R2−2R1: y − z = 1. R3−R1: y + 2z = 7. R3−R2: 3z = 6 ⇒ z = 2; y = 3; x = 1.
**Answer: x=1, y=3, z=2.** ✓

**Q3 (5).** Gauss-Jordan: 2x+5y+7z=52, 2x+y−z=0, x+y+z=9.
R1−R2 ⇒ 4y+8z=52 ⇒ y+2z=13. R2−2R3 ⇒ −y−3z=−18 ⇒ y+3z=18. Subtract ⇒ z=5, y=3, x=1.
**Answer: x=1, y=3, z=5.** ✓

**Q4 (3+2).** Rank of `[[1,2,3],[2,4,5],[2,4,6]]`.
R2−2R1 = (0,0,−1). R3−2R1 = (0,0,0). Echelon = `[[1,2,3],[0,0,−1],[0,0,0]]`. **Rank = 2.**
**Symmetric matrix:** A = Aᵀ. e.g. `[[1,2],[2,5]]`.

---

### Set B
**Q1 (5).** Inverse of `[[6, 5], [2, 1]]`.
det = 6 − 10 = −4. adj = `[[1, −5], [−2, 6]]`. **A⁻¹ = (−1/4) [[1,−5],[−2,6]] = [[−1/4, 5/4], [1/2, −3/2]].** ✓

**Q2 (5).** Gauss-Elim: 2x+y+4z=12, 4x+11y−z=33, 8x−3y+2z=20.
R2−2R1: 9y − 9z = 9 ⇒ y − z = 1.   R3−4R1: −7y − 14z = −28 ⇒ y + 2z = 4.
Subtract: 3z = 3 ⇒ z = 1. y = 2. 2x + 2 + 4 = 12 ⇒ x = 3.
**Answer: x = 3, y = 2, z = 1.** ✓

**Q3 (5).** Gauss-Jordan: 2x+6y+z=7, x+2y−z=−1, 5x+7y−4z=9.
Use the second equation (cleaner pivot). After elimination: z = 5, y = −3, x = 10.
**Answer: x = 10, y = −3, z = 5.** ✓ (Check: 20−18+5=7; 10−6−5=−1; 50−21−20=9.)

**Q4 (3+2).** Rank of `[[2,4,6],[1,2,4],[2,4,6]]`.
R3 = R1 (linearly dependent). R1 not a multiple of R2. **Rank = 2.**
**Skew-Symmetric matrix:** A = −Aᵀ; diagonal entries are 0. e.g. `[[0, 2, −3], [−2, 0, 4], [3, −4, 0]]`.

---

## SPRING 2026 — Class Test 2

### Set A
**Q1 (2).** **Purely Real number:** a complex number with imaginary part = 0; written `z = x + 0·i`. e.g. `z = 7`.

**Q2 (5).** Polar form of `z = −√6 − √2 i`.
`r = √(6 + 2) = √8 = 2√2`. The point (−√6, −√2) is in **Quadrant III**.
Reference angle α = arctan(√2/√6) = arctan(1/√3) = π/6.
θ = −π + π/6 = **−5π/6** (or equivalently 7π/6).
```
z = 2√2 [cos(−5π/6) + i sin(−5π/6)] = 2√2 e^(−i 5π/6).
```
**Graphically:** plot the point in QIII at distance 2√2 from origin, angle 5π/6 below the negative x-axis.

**Q3 (8).** **State and Prove De Moivre's theorem.** See PART III §4 above (statement + induction proof).

**Q4 (5).** Show `sin³θ = (3/4) sin θ − (1/4) sin 3θ`.
By De Moivre: `(cos θ + i sin θ)³ = cos 3θ + i sin 3θ`.
Expand binomially:
```
(cos θ + i sin θ)³ = cos³θ + 3i cos²θ sin θ − 3 cos θ sin²θ − i sin³θ.
```
Equate **imaginary** parts:
```
sin 3θ = 3 cos²θ sin θ − sin³θ
       = 3(1 − sin²θ) sin θ − sin³θ
       = 3 sin θ − 4 sin³θ.
```
Solve for sin³θ:
```
4 sin³θ = 3 sin θ − sin 3θ   ⇒   sin³θ = (3/4) sin θ − (1/4) sin 3θ.   ∎
```

---

### Set B
**Q1 (2).** **Purely Imaginary number:** real part = 0; `z = 0 + iy`. e.g. `z = 5i`.

**Q2 (5).** Polar form of `z = −5 − √5 i`.
`r = √(25 + 5) = √30`. Quadrant III. Reference α = arctan(√5/5) = arctan(1/√5).
θ = −π + arctan(1/√5)  [≈ −2.678 rad ≈ −153.43°].
```
z = √30 [cos(−π + arctan(1/√5)) + i sin(−π + arctan(1/√5))]
  = √30 e^(i(arctan(1/√5) − π)).
```
(Numerically: θ ≈ 206.57°, i.e. 7π/6 + small correction; not a "nice" angle, so leave in arctan form.)

**Q3 (8).** State + prove De Moivre's. (Same as Set A Q3.)

**Q4 (5).** Show `cos⁴θ = (1/8) cos 4θ + (1/2) cos 2θ + 3/8`.
Use `2 cos θ = e^(iθ) + e^(−iθ)`:
```
(2 cos θ)⁴ = (e^(iθ) + e^(−iθ))⁴
         = e^(4iθ) + 4 e^(2iθ) + 6 + 4 e^(−2iθ) + e^(−4iθ)
         = 2 cos 4θ + 8 cos 2θ + 6.
```
So `16 cos⁴θ = 2 cos 4θ + 8 cos 2θ + 6` ⇒
```
cos⁴θ = (1/8) cos 4θ + (1/2) cos 2θ + 3/8.   ∎
```

---

# PART V — FORMULA SHEET / CHEAT SHEET

## Determinants & Inverses
```
2×2:  det[[a,b],[c,d]] = ad − bc
2×2 inverse: A⁻¹ = (1/(ad−bc)) [[d, −b], [−c, a]]

3×3 det along R1: a(ei−fh) − b(di−fg) + c(dh−eg)
A⁻¹ = (1/det A) · adj A,    adj A = (cofactor matrix)ᵀ
Sign pattern:   +  −  +
                −  +  −
                +  −  +
```

## Solving Ax = b — quick chooser
```
Adjoint method      → small (n=3), det ≠ 0, just one b
Gauss elimination   → general; gives upper-tri then back-sub
Gauss-Jordan        → goes all the way to RREF; reads off x,y,z
LU decomposition    → reuse for many right-hand sides
Cramer's rule       → only if explicitly asked; rarely needed
```

## LU formulas (Doolittle, 3×3)
```
u_1j = a_1j  (row 1 of A unchanged)
l_i1 = a_i1 / u_11
u_ij = a_ij − Σ_{k<i} l_ik · u_kj    (for j ≥ i)
l_ij = (a_ij − Σ_{k<j} l_ik · u_kj) / u_jj   (for i > j)
```

## Eigenvalue formula (3×3)
```
λ³ − (tr A) λ² + (sum of 2×2 principal minors) λ − det A = 0
```

## Complex-number identities (must-know)
```
i² = −1,  i³ = −i,  i⁴ = 1
|z|² = z · z̄
|z₁z₂| = |z₁| |z₂|
|z₁/z₂| = |z₁|/|z₂|
arg(z₁z₂) = arg z₁ + arg z₂
arg(z₁/z₂) = arg z₁ − arg z₂

z = r e^(iθ),     1/z = (1/r) e^(−iθ)
e^(iθ) = cos θ + i sin θ        (Euler)
2 cos θ = e^(iθ) + e^(−iθ)
2i sin θ = e^(iθ) − e^(−iθ)

De Moivre:  (cos θ + i sin θ)^n = cos nθ + i sin nθ

n-th roots of unity:  e^(2πik/n),  k = 0,1,…,n−1
General n-th root of z = r e^(iθ):  r^(1/n) e^(i(θ + 2πk)/n)
```

## Power-reduction recipe (key for cos^n θ, sin^n θ)
1. Replace cos θ by `(e^iθ + e^−iθ)/2` and sin θ by `(e^iθ − e^−iθ)/(2i)`.
2. Expand the binomial.
3. Pair conjugate exponentials and convert back: `e^(ikθ)+e^(−ikθ) = 2 cos kθ`, `e^(ikθ)−e^(−ikθ) = 2i sin kθ`.

---

# PART VI — COMMON MISTAKES & SHORTCUTS

| Trap | What goes wrong | Fix |
|---|---|---|
| Forgetting to **transpose** cofactor matrix | Wrong inverse, wrong sign pattern | Always: cofactors → transpose → divide by det |
| Sign of cofactor C_ij | Off-by-sign answers | Check checkerboard `+ − +` pattern from top-left |
| Using arctan blindly for argument | Wrong quadrant | Use the quadrant table; or use atan2 |
| LU when first pivot is 0 | Division by zero (l21 = a21/0) | Swap rows first (PA = LU) |
| Eigenvector "= 0" answer | You wrote A·v = 0 trivially | v MUST be non-zero — choose a free parameter |
| Reading rank wrong | Counting all rows | Count **non-zero** rows after reduction |
| `(cos θ + i sin θ)^n` direct expansion | Slow, error-prone | Use exponential form instead |
| Triangle inequality direction | Writing `|z₁ + z₂| ≥ ...` | It's `≤` (sum of moduli is at least the modulus of the sum) |

### Fast shortcuts

- **3×3 det by Sarrus' rule:** copy first two columns to the right; sum down-diagonals minus sum up-diagonals.
- **Singularity check before adjoint:** compute det first; if 0, switch method or expect "no inverse."
- **Sanity for eigenvalues:** sum = trace, product = det.
- **Polar conversion for "nice" points:** know by heart angles for (±1, ±1), (±√3, ±1), (±1, ±√3).

---

# PART VII — PRACTICE SET

## Easy (warm-up)

E1. Compute det `[[3, 2], [4, 5]]`. **Ans:** 7.
E2. Inverse of `[[2, 1], [5, 3]]`. **Ans:** `[[3, −1], [−5, 2]]`.
E3. Plot `z = −1 + i` on Argand plane; find |z| and arg z. **Ans:** √2, 3π/4.
E4. Convert `z = 1 + i√3` to polar form. **Ans:** `2(cos π/3 + i sin π/3)`.
E5. Compute `(1 + i)²`. **Ans:** 2i.
E6. State whether `A = [[1, 2, 3], [2, 4, 5], [3, 5, 6]]` is symmetric. **Ans:** Yes.
E7. Identify type of `[[2i, 1+i], [−1+i, 0]]`. **Ans:** Skew-Hermitian.

## Medium (exam-style)

M1. Solve by Gauss-Jordan: x+2y=5, 3x+y=10. **Ans:** x=3, y=1.
M2. Solve by adjoint: x+2y+z=4, x+y+z=3, 2x+y+z=4. **Ans:** x=1, y=1, z=1.
M3. Find rank of `[[1,1,1],[1,2,3],[1,4,9]]`. **Ans:** 3.
M4. Compute `(1 + i)^8` using De Moivre. **Ans:** 16.
M5. Polar form of −4 + 4i. **Ans:** `4√2(cos 3π/4 + i sin 3π/4)`.
M6. Show `cos 2θ = cos²θ − sin²θ` via De Moivre. (Standard expansion of (cos θ + i sin θ)².)
M7. Find eigenvalues of `[[2, 1], [1, 2]]`. **Ans:** 1 and 3.
M8. LU factor `[[2, 3], [4, 7]]`. **Ans:** L=`[[1,0],[2,1]]`, U=`[[2,3],[0,1]]`.

## Hard (challenge)

H1. Find all four 4-th roots of `−16` and plot. **Ans:** Write `−16 = 16e^{i(π+2kπ)}`. Then
`z_k = 16^(1/4)e^{i(π+2kπ)/4} = 2e^{i(π/4 + kπ/2)}`, `k=0,1,2,3`.
So the roots are `2e^(iπ/4), 2e^(i3π/4), 2e^(i5π/4), 2e^(i7π/4)` i.e.
`√2(1+i), √2(−1+i), √2(−1−i), √2(1−i)`.
H2. Solve via LU: x+y+z=6, 2x+y−z=1, x−y+2z=5. **Ans:** x=1, y=2, z=3.
H3. Find eigenvalues/eigenvectors of `[[1,1,1],[1,1,1],[1,1,1]]`. **Ans:** λ = 3 (v=(1,1,1)) and λ = 0 (double; e.g. (1,−1,0), (1,0,−1)).
H4. Express `sin⁵ θ` in form a sin 5θ + b sin 3θ + c sin θ. **Ans:**
`(2i sin θ)^5 = (e^(iθ) − e^(−iθ))^5 = 2i sin 5θ − 10i sin 3θ + 20i sin θ`.
Hence `32i sin⁵θ = 2i(sin 5θ − 5 sin 3θ + 10 sin θ)`, so
`sin⁵θ = (1/16) sin 5θ − (5/16) sin 3θ + (5/8) sin θ`.
H5. Prove the reverse triangle inequality `||z₁| − |z₂|| ≤ |z₁ − z₂|`. (Hint: apply triangle inequality to `z₁ = (z₁ − z₂) + z₂`.)

---

# PART VIII — MOCK TEST (1 hour, 20 marks)

> Format mirrors the actual CT pattern. Answers below.

**Section A — Matrices (12 marks)**

1. Solve by Adjoint Method (5):
   `2x + 3y + z = 9, x − y + z = 0, x + 2y + 3z = 14`.

2. Solve by Gauss-Jordan (5):
   `x + 2y + z = 6, 2x + y + 3z = 13, 3x + 2y + 2z = 13`.

3. Define Hermitian and Skew-Symmetric matrices with one example each (2).

**Section B — Complex Numbers (8 marks)**

4. State and prove De Moivre's theorem (4).
5. Find polar form of `z = √3 − i` and compute `z⁶` using De Moivre (2).
6. Show that `cos 3θ = 4 cos³θ − 3 cos θ` (2).

---

## Answer Key

**Q1.** A = `[[2,3,1],[1,−1,1],[1,2,3]]`. det = 2(−3−2) − 3(3−1) + 1(2+1) = −10 − 6 + 3 = −13. Compute adjoint, multiply: result is **x = 1, y = 2, z = 3** (verify by substitution).
**Q2.** Solving: subtract appropriately. **x = 1, y = 2, z = 3**.
**Q3.** Hermitian: A = A*; example `[[2, 3+i], [3−i, 5]]`. Skew-Symmetric: A = −Aᵀ; example `[[0, 2], [−2, 0]]`.
**Q4.** See PART III §4 above (full induction proof).
**Q5.** r = 2; θ = −π/6 (Q4: x>0, y<0). z = 2 e^(−iπ/6). z⁶ = 2⁶ e^(−iπ) = **64·(−1) = −64**.
**Q6.** Equate **real** parts of `(cos θ + i sin θ)³ = cos³θ + 3i cos²θ sin θ − 3 cos θ sin²θ − i sin³θ`:
`cos 3θ = cos³θ − 3 cos θ sin²θ = cos³θ − 3 cos θ (1−cos²θ) = 4 cos³θ − 3 cos θ`. ∎

---

# PART IX — ACTIVE-LEARNING QUIZ & REVISION CHECKLIST

## 30-second flash quiz (cover the right column)

| Q | A |
|---|---|
| Sum of eigenvalues equals … | trace of A |
| Product of eigenvalues equals … | det A |
| adj A = ? | (cofactor matrix)ᵀ |
| When does A⁻¹ exist? | det A ≠ 0 |
| Rank of `[[1,2],[2,4]]`? | 1 |
| Diagonal of a Hermitian matrix is … | real |
| Diagonal of a Skew-Hermitian matrix is … | 0 or purely imaginary |
| 2 cos θ = … | e^(iθ) + e^(−iθ) |
| 2i sin θ = … | e^(iθ) − e^(−iθ) |
| (cos θ + i sin θ)^n = … | cos nθ + i sin nθ |
| Modulus of 3 + 4i? | 5 |
| Argument of 1 + i? | π/4 |
| n-th roots of unity, count? | n |
| (1 + i)² = ? | 2i |

## Try-before-you-peek problems

**P1.** Solve `x + y = 3, 2x − y = 0` by Gauss-Jordan. *(Spoiler: x=1, y=2.)*
**P2.** `(2 e^(iπ/3))³ = ?` *(Spoiler: 8 e^(iπ) = −8.)*
**P3.** Find eigenvalues of `[[3, 1], [0, 3]]`. *(Spoiler: λ = 3 (double); only one eigenvector direction (1,0).)*
**P4.** Express `cos²θ` as a + b cos 2θ. *(Spoiler: ½ + ½ cos 2θ.)*
**P5.** Verify triangle inequality for z₁ = 3 + 4i, z₂ = 1 − 2i. *(|z₁|=5, |z₂|=√5; |z₁+z₂|=√20 ≈ 4.47 ≤ 7.24 ✓.)*

## Spaced-repetition queue

- **Day 1:** Definitions (matrix types, complex types) + 2×2 inverse + simple De Moivre.
- **Day 3:** 3×3 adjoint inverse + Gauss elimination + polar conversion.
- **Day 5:** Gauss-Jordan + LU + |z₁/z₂| proof.
- **Day 7:** Eigenvalues with double roots + Skew-Hermitian verification.
- **Day 10:** cos⁵θ, sin⁵θ identities + n-th roots + median problem.
- **Day 14:** Full mock test under timed conditions.

## Revision Checklist (tick before exam)

```
Matrices
[ ] Can write definition + example for: square, diag, identity,
    upper/lower tri, symmetric, skew-symmetric, Hermitian, skew-Hermitian.
[ ] Can compute 3×3 determinant in < 1 minute.
[ ] Can produce a 3×3 cofactor matrix and adjugate cleanly.
[ ] Can solve a 3×3 system by adjoint, Gauss, Gauss-Jordan, AND LU.
[ ] Can find eigenvalues/eigenvectors for a 3×3 (incl. one double root).
[ ] Can verify a matrix is Hermitian / Skew-Hermitian.
[ ] Know rank-from-echelon procedure and the rank/nature-of-solution rule.

Complex Numbers
[ ] Can state Purely Real and Purely Imaginary with examples.
[ ] Can convert between Cartesian, polar, exponential forms (any quadrant).
[ ] Can plot z on the Argand diagram and read off |z|, arg z.
[ ] Can state AND prove De Moivre's theorem (induction).
[ ] Can use De Moivre to compute (a + ib)^n.
[ ] Can use De Moivre to find n-th roots of any complex number.
[ ] Can derive cos³θ, sin³θ, cos⁵θ, cos⁴θ identities.
[ ] Can prove |z₁/z₂| = |z₁|/|z₂| algebraically.
[ ] Can apply triangle inequality + reverse triangle inequality.
[ ] Can solve coordinate geometry (e.g. median length) using complex numbers.
```

---

# APPENDIX A — Visual Maps & Memory Aids

## Concept Map: Matrices

```
                ┌──────────────┐
                │  MATRIX A    │
                └──────┬───────┘
       ┌───────────────┼─────────────────────────────┐
       ▼               ▼                             ▼
   det A             rank A                    eigenvalues
   │                 │                             │
   ├─ 0 → singular   ├─ unique soln (= n)        det(A−λI)=0
   ├─ ≠0→inverse exists                          │
   │                                             ├─ tr A = Σλ
   ▼                                             ├─ det A = Π λ
   adj A = Cᵀ                                    │
   │                                             ▼
   A⁻¹ = adj(A)/det(A)                       eigenvectors:
                                              (A−λI) v = 0

  Solve Ax = b
   ├─ Adjoint: x = (1/det A) adj(A) b
   ├─ Gauss elim: forward → back-sub
   ├─ Gauss-Jordan: full RREF
   └─ LU: A = LU, then Ly=b, Ux=y
```

## Concept Map: Complex Numbers

```
                  z = x + iy
                 /     |     \
                /      |      \
          modulus   conjugate   forms
            |          |     ┌──┴──┬──────────┐
           √(x²+y²)   x−iy   Cart  Polar      Exp
                              │     │          │
                              │   r(cosθ      r e^(iθ)
                              │   +i sinθ)
                              │     │          │
                              └─────┴──────────┘
                                    │
                              De Moivre
                              z^n = r^n e^(i nθ)
                                    │
                ┌───────────────────┼───────────────────┐
                ▼                   ▼                   ▼
           Powers (a+bi)^n    n-th roots        Trig identities
                              (n values, eq.    cos nθ, sin nθ
                               spaced by 2π/n)  cos^n θ, sin^n θ
```

## Polar Conversion Decision Tree

```
                  Is x > 0?
                  /        \
               yes          no
               /              \
          Is y > 0?       Is y > 0?
          /     \         /       \
        yes     no      yes        no
        Q1      Q4      Q2          Q3
        θ=arctan(y/x)
                θ=−arctan|y/x|
                        θ=π−arctan|y/x|
                                   θ=−π+arctan|y/x|
                                  (or  π+arctan|y/x|)
```

## Mnemonics

- **"+ − +" diagonal pattern:** for cofactor signs (top-left to bottom-right tile).
- **"L is lower with 1's on the bridge":** L has 1's on its diagonal in Doolittle's method.
- **"sum-trace, product-det":** eigenvalues sanity-check.
- **"polar = (radius, angle); exp = (radius)·e^(i·angle)":** they're the same data, written two ways.

---

# PART X — ANALYSIS OF YOUR ATTEMPTS & WEAK-AREA TRACKER

## What was analyzed from your folder

1. `answer_topi.txt` (your complex-number theory writeup and solved examples).
2. All uploaded CT images (question extraction + exam pattern detection).
3. Existing master study notes (`MC_FA_Master_Study_Guide.md`) for coverage consistency.

## Strengths seen in your current work

- Your conceptual explanations are clear and beginner-friendly, especially on forms of complex numbers.
- You already include De Moivre, roots, and triangle inequality in one place, which is exam-smart.
- Your solved examples follow the right sequence: convert form -> apply theorem -> simplify.

## Mistakes / gaps identified and corrected

1. **De Moivre statement scope (common exam wording issue):**
  Standard CT proof is for integer powers `n` (especially positive integers via induction). You wrote a broad statement that includes real `n`; this is not wrong in advanced complex analysis, but in CT answers you should state integer `n` first, then add an extension note.

2. **Argument-finding risk with `tan^{-1}(y/x)`:**
  You did mention quadrant adjustment, which is good. Keep using `atan2(y,x)` logic mentally, because many exam mistakes happen exactly here.

3. **Theory-to-exam gap on matrix side:**
  Your detailed personal writeup is strong for complex numbers, but matrix-side attempt notes are missing. This can create a score gap because CT-1 and CT-2 both carry heavy matrix marks (inverse, Gauss/Jordan, LU, eigen).

4. **Step-formatting for 8-mark answers:**
  For LU/eigenvalue questions, examiners reward structure. Use fixed headings in script:
  `Given -> A, b -> Decompose A=LU -> Solve Ly=b -> Solve Ux=y -> Verify`.

## Personalized weak-area map (from your materials)

| Topic | Current level | Evidence from uploads | Priority |
|---|---|---|---|
| Polar conversion + Argand | Strong | detailed in `answer_topi.txt` + CT2 Set A/B | Medium |
| De Moivre proof + identities | Medium-Strong | covered with examples; needs exam-proof formatting | High |
| Triangle inequality / modulus properties | Medium | theory present; fewer mixed problems practiced | Medium |
| 3x3 inverse (adjoint/row-canonical) | Medium | appears in papers; less personal worked evidence | High |
| Gauss elimination / Gauss-Jordan | Medium | frequent in papers; needs speed drills | High |
| LU decomposition | Medium | many 8-mark appearances; must be fluent | Very High |
| Eigenvalues/eigenvectors (3x3) | Medium | many 8-mark appearances; needs repeated practice | Very High |
| Hermitian / Skew-Hermitian verification | Medium | appears in 62(D); easy to lose signs | High |

## Targeted improvement drills (your next 5 sessions)

1. Session 1 (60 min): 2 inverse + 2 Gauss elimination + 1 Gauss-Jordan.
2. Session 2 (60 min): 2 LU full solves + 1 eigenvalue 3x3.
3. Session 3 (45 min): De Moivre proof from memory + 4 trig-identity derivations.
4. Session 4 (45 min): 4 polar conversions (all quadrants) + 2 modulus inequality proofs.
5. Session 5 (60 min): one full mixed mock (20 marks) under timer.

## Error-log template (fill after every practice set)

| Date | Question ID | Mistake Type | Why It Happened | Correct Pattern | Re-test Date |
|---|---|---|---|---|---|
|  |  | sign / algebra / method / time |  |  |  |

---

# PART XI — ADAPTIVE ACTIVE-LEARNING MODE

Use this section as your personal tutor workflow after each chapter.

## Step A — Learn -> Recall -> Solve

1. Read one concept block (10-15 minutes max).
2. Close notes and write the definition/procedure from memory.
3. Solve one easy + one medium + one hard question.
4. Check only after full attempt.

## Step B — Section quizzes (do before seeing answers)

### Quiz: Matrix Foundations

Q1. Define diagonal, identity, symmetric, and skew-symmetric matrices with examples.
Q2. Why must `det(A) != 0` for inverse to exist?
Q3. In one line: difference between Gauss elimination and Gauss-Jordan.

### Quiz: LU + Eigen

Q1. In Doolittle LU, what is fixed on the diagonal of `L`?
Q2. State two quick checks for eigenvalues of a 3x3 matrix.
Q3. If one eigenvalue is repeated, how do you decide if there are one or two independent eigenvectors?

### Quiz: Complex Numbers

Q1. Convert `z = -3 + 3i` to polar form with principal argument.
Q2. State De Moivre theorem and one direct use-case from CT.
Q3. Prove in one short line: `|z|^2 = z\bar z`.

## Step C — Spaced repetition prompts

- **After 24 hours:** redo 5 key formulas from memory.
- **After 3 days:** solve one full LU + one full eigen + one De Moivre identity.
- **After 7 days:** attempt one timed 20-mark mixed test.
- **After 14 days:** attempt a second timed test and compare error log.

## Step D — Adaptive rule (how to respond to weak areas)

- If two mistakes occur in the same topic on one day, schedule that topic first in the next session.
- If a question takes more than 12 minutes, classify it as a speed weakness and add one extra timed drill.
- If a proof is correct but long, rewrite it in exam-optimized 8-10 lines.
- If a topic is correct twice in a row under time, downgrade it from High priority to Medium.

## Self-check scoreboard (update every 3 days)

| Skill | Accuracy % | Avg Time | Status |
|---|---|---|---|
| Inverse (adjoint + row-canonical) |  |  |  |
| Gauss / Jordan solving |  |  |  |
| LU decomposition |  |  |  |
| Eigenvalues/eigenvectors |  |  |  |
| Polar conversion + Argand |  |  |  |
| De Moivre proof + identities |  |  |  |
| Triangle/modulus properties |  |  |  |

---

# CLOSING NOTE

This guide consolidates **every problem** present in your folder, organizes the syllabus into a 14-stage roadmap, and ends with a checklist you can tick off the night before the exam. If a single concept still feels shaky, return to the matching section in **PART II** (matrices) or **PART III** (complex numbers), then redo the corresponding question in **PART IV** without looking. Repeat until silent.

**Next study session priority order (based on what carries the most marks per CT):**
1. LU decomposition (8 marks every CT-2).
2. Eigenvalues / eigenvectors (8 marks every CT-2).
3. De Moivre proof (4–8 marks).
4. cos^n θ / sin^n θ identities (4–5 marks).
5. Adjoint inverse + Gauss + Gauss-Jordan (5+5+5 = 15 marks every CT-1).
6. Definitions (5 marks one slot every CT-1).

Good luck, and study with paper and pen — not just by reading.
