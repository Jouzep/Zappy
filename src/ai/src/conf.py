# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

import os
import sys
sys.path.insert(0, os.path.abspath('.'))

import main
import zappy_ai
import usage
import tcp_client
import player
import parsing
import myparser
import myexception
import movement
import macro
import level
import items
import fork


project = 'Zappy'
copyright = '2023, Vincent Shao, Steven Dong, Joseph Yu, Jeras Bertine, David Lin'
author = 'Vincent Shao, Steven Dong, Joseph Yu, Jeras Bertine, David Lin'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    'sphinx.ext.autodoc'
]

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']



# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'alabaster'
html_static_path = ['_static']
