src_test = [
    'tests_list_set.c',
    'tests_list_contain.c',
    'tests_list_sub_list.c',
    'tests_list_to_array.c',
    'tests_list_remove.c',
    'tests_list_stat.c',
    'tests_list_clone.c',
    'tests_list_remove_data.c',
    'tests_list_index_of.c',
    'tests_list_add.c',
    'tests_list_reverse.c',
    'tests_list_remove_range.c',
    'tests_list_count.c',
    'tests_list_get.c',
    'tests_list.c',
    'tests_list_destructor.c'
]

criterion = dependency('criterion', fallback: ['criterion', 'criterion'])
test_exe = executable('unit_tests', src_test, include_directories: include, link_with: liblist, dependencies: criterion)
test('liblist test', test_exe)
