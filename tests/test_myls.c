#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_ls, should_handle_no_flags_and_no_files, .init = redirect_all_std)
{
int argc = 2;
char *argv[] = {"./my_ls", "/path/to/empty/directory", NULL};

cr_assert_eq(main(argc, argv), 0);
cr_assert_stdout_eq_str("");
}

Test(my_ls, should_handle_no_flags_and_hidden_files, .init = redirect_all_std)
{
int argc = 2;
char *argv[] = {"./my_ls", "/path/to/directory/with/hidden/files", NULL};

cr_assert_eq(main(argc, argv), 0);
cr_assert_stdout_neq_str(".hidden_file");
}

Test(my_ls, should_handle_invalid_directory, .init = redirect_all_std)
{
int argc = 2;
char *argv[] = {"./my_ls", "/invalid/directory", NULL};

cr_assert_eq(main(argc, argv), 84);
}

Test(my_lsl, should_handle_no_files, .init = redirect_all_std)
{
int argc = 3;
char *argv[] = {"./my_ls", "-l", "/path/to/empty/directory", NULL};

cr_assert_eq(main(argc, argv), 0);
cr_assert_stdout_eq_str("");
}

Test(my_lsl, should_handle_hidden_files, .init = redirect_all_std)
{
int argc = 3;
char *argv[] = {"./my_ls", "-l", "/path/to/directory/with/hidden/files", NULL};

cr_assert_eq(main(argc, argv), 0);
cr_assert_stdout_neq_str(".hidden_file");
}

Test(my_lsl, should_handle_invalid_directory, .init = redirect_all_std)
{
int argc = 3;
char *argv[] = {"./my_ls", "-l", "/invalid/directory", NULL};

cr_assert_eq(main(argc, argv), 84);
}