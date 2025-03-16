
typedef struct float_vector FVector;

FVector * FVector_create(int capacity);
void FVector_destroy(FVector **vec_ref);
int FVector_size(const FVector *vec);
int FVector_capacity(const FVector *vec);
float FVector_at(const FVector *vec, int index);
float FVector_get(const FVector *vec, int index);
void FVector_append(const FVector *vec, float val);
void FVector_set(const FVector *vec, int index, float val);
void FVector_print(const FVector *vec); 