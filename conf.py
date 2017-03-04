# -*- coding: utf-8 -*-

import os
import sys
sys.path.insert(0, os.path.abspath('.'))


# -- General configuration ------------------------------------------------

extensions = ['sphinx.ext.githubpages']
templates_path = ['_templates']
source_suffix = '.rst'
master_doc = 'index'
project = u'gCompiler'
copyright = u'2017, Roie R. Black'
author = u'Roie R. Black'
version = u'0.1'
release = u'Spring2017'
language = None
pygments_style = 'sphinx'

todo_include_todos = False
exclude_patterns = [
    'README.rst',
    '_build', 
    '.DS_Store', 
    '_venv']

# -- Options for HTML output ----------------------------------------------

html_theme = 'alabaster'
# html_theme_options = {}
html_static_path = ['_static']

# -- Options for LaTeX output ---------------------------------------------

latex_elements = {
    'papersize': 'letterpaper',
    'pointsize': '12pt',
    'figure_align': 'htbp',
}
latex_documents = [
    (master_doc, 'gCompiler.tex', u'gCompiler Design Notes',
     u'Roie R. Black', 'manual'),
]
