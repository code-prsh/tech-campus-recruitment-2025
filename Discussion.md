## Solutions Considered

### 1. **Loading the Entire File into Memory**
- **Approach:** Read the entire 1TB log file into memory and filter logs for the given date.
- **Pros:** Simple implementation.
- **Cons:** Not feasible due to extreme memory usage and performance bottlenecks.

### 2. **Using Indexed Storage (Database Approach)**
- **Approach:** Preprocess the log file into a database (e.g., SQLite, MySQL) and query logs efficiently.
- **Pros:** Fast retrieval times after preprocessing.
- **Cons:** Requires preloading and indexing, which is impractical for dynamically growing logs.

### 3. **Streaming File Processing (Final Choice)**
- **Approach:** Read the log file **line by line** using `std::ifstream`, match logs by date, and write relevant logs to an output file.
- **Pros:** Low memory usage, fast execution, works on large files efficiently.
- **Cons:** Still requires a full file scan but optimally handles large data sizes.

## Final Solution Summary
The **streaming file processing approach** was chosen due to its efficiency in handling large files without excessive memory usage. The solution reads the file line by line, checks if a line starts with the requested date, and writes matching logs to an output file.

## Steps to Run the Solution

### 1. **Compile the Code**
Run the following command to compile the C++ program:
```sh
 g++ -o extract_logs.exe extract_logs.cpp
```

### 2. **Run the Program**
Use the following command, passing the required date:
```sh
 extract_logs.exe 2024-12-01
```
This extracts logs for `2024-12-01` and saves them to `output/output_2024-12-01.txt`.

### 3. **Expected Output Format**
```
2024-12-01 14:23:45 INFO User logged in  
2024-12-01 14:24:10 ERROR Failed to connect to the database  
```

## Edge Cases Considered
- **Missing Log File:** The program checks if the file exists before processing.
- **File Permission Issues:** Ensured error handling for unreadable files.
- **Handling Large Files Efficiently:** Uses streaming processing instead of loading into memory.
- **Incorrect Date Format:** Validates user input to ensure proper date format.

## Conclusion
This solution provides an efficient, scalable approach to log retrieval from large files while optimizing performance and memory usage. Future improvements could include **indexing logs by date** or **using multi-threading for parallel searches** to enhance performance.

