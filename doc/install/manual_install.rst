.. include:: ../links.inc

.. _manual-install:
.. _standard-instructions:

Install via :code:`pip` or :code:`conda`
========================================

.. hint::
   If you're unfamiliar with Python, we recommend using our :ref:`installers`
   instead.

MNE-Python requires Python version |min_python_version| or higher. If you
need to install Python, please see :ref:`install-python`.

- If you only need MNE-Python's core functionality including 2D plotting (but
  **without 3D visualization**), install via :code:`pip`:

  .. code-block:: console

      pip install mne

  or via :code:`conda`:

  .. code-block:: console

      conda install --channel=conda-forge mne-base

- If you plan to use MNE-Python's functions that require **HDF5 I/O** (this
  includes :func:`mne.io.read_raw_eeglab`, :meth:`mne.SourceMorph.save`, and
  others), you should run via :code:`pip`:

  .. code-block:: console

      pip install mne[hdf5]

  or via :code:`conda`

  .. code-block:: console

     conda install --channel=conda-forge mne-base h5io h5py pymatreader

  to install the necessary dependencies.

- If you need MNE-Python **with 3D visualization** capabilities (e.g., plotting
  estimated source activity on a cortical surface) it is a good idea to install
  MNE-Python into its own ``conda`` environment. To do this:

  .. code-block:: console

     conda create --name=mne --channel=conda-forge mne
     #                   ↑↑↑                       ↑↑↑
     #             environment name            package name

  This will create a new ``conda`` environment called ``mne`` and install all
  dependencies into it. If you need to convert structural MRI scans into models
  of the scalp, inner/outer skull, and cortical surfaces, you will also need
  :doc:`FreeSurfer <freesurfer>`.

The :ref:`advanced_setup` page has additional
tips and tricks for special situations (servers, notebooks, CUDA, installing
the development version, etc). The :ref:`contributing` has additional
installation instructions for (future) contributors to MNE-Python (e.g, extra
dependencies for running our tests and building our documentation).

Python IDEs
===========

Most users find it convenient to write and run their code in an `Integrated
Development Environment`_ (IDE). Some popular choices for scientific
Python development are:

- `Spyder`_ is a free and open-source IDE developed by and for scientists who
  use Python. It is included by default in the ``base`` environment when you
  install Anaconda, and can be started from a terminal with the command
  ``spyder`` (or on Windows or macOS, launched from the Anaconda Navigator GUI).
  It can also be installed with `dedicated installers <https://www.spyder-ide.org/#section-download>`_.
  To avoid dependency conflicts with Spyder, you should install ``mne`` in a
  separate environment, like explained in the earlier sections. Then, set
  Spyder to use the ``mne`` environment as its default interpreter by opening
  Spyder and navigating to
  :samp:`Tools > Preferences > Python Interpreter > Use the following interpreter`.
  There, paste the output of the following terminal commands::

      $ conda activate mne
      $ python -c "import sys; print(sys.executable)"

  It should be something like ``C:\Users\user\anaconda3\envs\mne\python.exe``
  (Windows) or ``/Users/user/opt/anaconda3/envs/mne/bin/python`` (macOS).

  If the Spyder console can not start because ``spyder-kernels`` is missing,
  install the required version in the ``mne`` environment with the following
  commands in the terminal::

      $ conda activate mne
      $ conda install spyder-kernels=HERE_EXACT_VERSION -c conda-forge

  Refer to the `spyder documentation <https://docs.spyder-ide.org/current/troubleshooting/common-illnesses.html#spyder-kernels-not-installed-incompatible>`_
  for more information about ``spyder-kernels`` and the version matching.

  If the Spyder graphic backend is not set to ``inline`` but to e.g. ``Qt5``,
  ``pyqt`` must be installed in the ``mne`` environment.

- `Visual Studio Code`_ (often shortened to "VS Code" or "vscode") is a
  development-focused text editor that supports many programming languages in
  addition to Python, includes an integrated terminal console, and has a rich
  ecosystem of packages to extend its capabilities. Installing
  `Microsoft's Python Extension
  <https://marketplace.visualstudio.com/items?itemName=ms-python.python>`__ is
  enough to get most Python users up and running. VS Code is free and
  open-source.
- `PyCharm`_ is an IDE specifically for Python development that provides an
  all-in-one installation (no extension packages needed). PyCharm comes in a
  free "community" edition and a paid "professional" edition, and is
  closed-source.
