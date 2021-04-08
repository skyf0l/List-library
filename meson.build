project('liblist', 'c', default_options: ['default_library=both', 'warning_level=2'] )

add_global_arguments('-fdiagnostics-color=always', language: 'c')

include = include_directories('include', 'include/private', 'subprojects')

subdir('include')
subdir('src')

if get_option('tests')
    subdir('tests')
endif

liblist_dep = declare_dependency(include_directories : include, link_with : liblist)

pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries : liblist, version: '1.0', name: 'liblist', filebase : 'liblist', description : 'List library in C')
