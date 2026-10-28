int main(void)
{
    const char hello[] = "Hello, world!";

    asm volatile(
        // RAX register determines the system call (syscall) number for the OS to execute.
        // Think of the RAX register as an index of commands, where each number signals a function.
        // RAX set to 0 = sys_read   | Read data (e.g., from keyboard)
        // RAX set to 1 = sys_write  | Write data (e.g., to screen or file)
        // RAX set to 60 = sys_exit  | Terminate and close the program
        // Since our goal is to display text on the screen, we need the write function.
        // Therefore, we set the RAX register to 1, aka sys_write.
        "mov $1, %%rax\n\t"

        // RDI register holds the 1st argument for Linux system calls.
        // For sys_write, the 1st argument is the File Descriptor (where to send the data):
        // RDI set to 0 = stdin    | Keyboard input
        // RDI set to 1 = stdout   | Standard screen output (normal program output)
        // RDI set to 2 = stderr   | Standard error screen output (error messages)
        // Since we are creating a print function, the primary goal is regular screen output.
        // Therefore, we set the RDI register to 1, aka stdout.
        "mov $1, %%rdi\n\t"

        // RSI register holds the 2nd argument for Linux system calls.
        // For sys_write, this must be the memory address (pointer) of the character buffer.
        // The compiler passes the address of 'hello' via the %0 placeholder.
        "mov %0, %%rsi\n\t"

        // RDX register holds the 3rd argument for Linux system calls.
        // For sys_write, this is the exact number of bytes (characters) to print.
        // Note on calling conventions:
        // On Linux/macOS function calls, RDX is the 3rd argument (RDI, RSI, RDX).
        // On Windows function calls, RDX is the 2nd argument (RCX, RDX, R8, R9).
        // However, Windows does NOT use the 'syscall' instruction for standard printing.
        // For this Linux system call, it acts as our 3rd argument.
        // "Hello, world!" is exactly 13 characters long.
        "mov $13, %%rdx\n\t"

        "syscall\n\t"
        :
        : "r"(hello)
        : "rax", "rdi", "rsi", "rdx", "memory");

    // We also need to create an Exit syscall
    // In case there's an error in compilation, we need to be able to catch it
    asm volatile(
        "mov $60, %%rax\n\t" // rax = 60 (sys_exit)
        "mov $0, %%rdi\n\t"  // exit code = 0
        "syscall\n\t"
        ::: "%rax", "%rdi");

    return 0;
}