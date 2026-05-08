# Custom Memory Allocator

A custom implementation of `malloc`, `free`, `calloc`, and `realloc` written in C. This project focuses on low-level memory management, heap allocation strategies, pointer arithmetic, block splitting, block coalescing, and allocator performance comparisons.

---

## Features

- Custom `malloc()` implementation
- Custom `free()` implementation
- Custom `calloc()` implementation
- Custom `realloc()` implementation
- Free list management
- Block splitting when free blocks are larger than requested memory
- Block coalescing when adjacent blocks are freed
- Heap growth using system-level memory management
- Allocation statistics tracking
- Multiple allocation strategies:
  - First Fit
  - Next Fit
  - Best Fit
  - Worst Fit

---

## Technologies Used

- C
- Linux
- Makefile
- GDB
- LD_PRELOAD
- Git/GitHub

---

## Concepts Learned

This project helped strengthen understanding of:

- Dynamic memory allocation
- Heap management
- Pointer arithmetic
- Linked list-based free lists
- Memory fragmentation
- System-level debugging
- Shared libraries
- Performance tradeoffs between allocation strategies

---

## Allocation Strategies

### First Fit
Searches the free list and uses the first available block large enough for the request.

### Next Fit
Continues searching from the last allocated position instead of starting from the beginning each time.

### Best Fit
Finds the smallest free block that can satisfy the request to reduce wasted space.

### Worst Fit
Finds the largest available free block and splits it when possible.

---

## Building the Project

Compile the project using:

```bash
make
```

This generates shared libraries for the different allocation strategies.

---

## Running Tests

Example using the First Fit allocator:

```bash
env LD_PRELOAD=lib/libmalloc-ff.so tests/ffnf
```

Other allocator versions can be tested by changing the shared library:

```bash
env LD_PRELOAD=lib/libmalloc-bf.so tests/bfwf
env LD_PRELOAD=lib/libmalloc-nf.so tests/ffnf
env LD_PRELOAD=lib/libmalloc-wf.so tests/bfwf
```

---

## Example Output

```text
mallocs: 8
frees: 8
reuses: 1
grows: 5
splits: 1
coalesces: 1
blocks: 5
requested: 7298
max heap: 4096
```

---

## Debugging

Because this project overrides the system allocator, debugging required loading the custom allocator through `LD_PRELOAD`.

Example with GDB:

```bash
gdb ./tests/ffnf
```

Inside GDB:

```bash
set exec-wrapper env LD_PRELOAD=./lib/libmalloc-ff.so
run
where
```

---

## Future Improvements

- Add more detailed fragmentation metrics
- Improve benchmark coverage
- Add visualization of free list changes
- Optimize allocation strategy selection
- Add additional stress tests for edge cases

---

## Author

Muhammad Zahid
