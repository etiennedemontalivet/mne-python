.. _changes_0_12:

Version 0.12 (2016-05-10)
-------------------------

Changelog
~~~~~~~~~

- Add ``overlay_times`` parameter to :func:`mne.viz.plot_epochs_image` to be able to display for example reaction times on top of the images, by `Alex Gramfort`_

- Animation for evoked topomap in :func:`mne.Evoked.animate_topomap` by `Jaakko Leppakangas`_

- Make :func:`mne.channels.find_layout` more robust for KIT systems in the presence of bad or missing channels by `Jaakko Leppakangas`_

- Add raw movement compensation to :func:`mne.preprocessing.maxwell_filter` by `Eric Larson`_

- Add :class:`mne.Annotations` for for annotating segments of raw data by `Jaakko Leppakangas`_

- Add reading of .fif file montages by `Eric Larson`_

- Add system config utility :func:`mne.sys_info` by `Eric Larson`_

- Automatic cross-validation and scoring metrics in ``mne.decoding.GeneralizationAcrossTime``, by `Jean-Remi King`_

- ``mne.decoding.GeneralizationAcrossTime`` accepts non-deterministic cross-validations, by `Jean-Remi King`_

- Add plotting RMS of gradiometer pairs in :func:`mne.viz.plot_evoked_topo` by `Jaakko Leppakangas`_

- Add regularization methods to :func:`mne.compute_raw_covariance` by `Eric Larson`_.

- Add command ``mne show_info`` to quickly show the measurement info from a .fif file from the terminal by `Alex Gramfort`_.

- Add creating forward operator for dipole object :func:`mne.make_forward_dipole` by `Chris Bailey`_

- Add reading and estimation of fixed-position dipole time courses (similar to Elekta ``xfit``) using :func:`mne.read_dipole` and :func:`mne.fit_dipole` by `Eric Larson`_.

- Accept ``mne.decoding.GeneralizationAcrossTime``'s ``scorer`` parameter to be a string that refers to a scikit-learn_ metric scorer by `Asish Panda`_.

- Add method :func:`mne.Epochs.plot_image` calling :func:`mne.viz.plot_epochs_image` for better usability by `Asish Panda`_.

- Add :func:`mne.io.read_raw_cnt` for reading Neuroscan CNT files by `Jaakko Leppakangas`_

- Add ``decim`` parameter to ``mne.time_frequency.cwt_morlet``, by `Jean-Remi King`_

- Add method :func:`mne.Epochs.plot_topo_image` by `Jaakko Leppakangas`_

- Add the ability to read events when importing raw EEGLAB files, by `Jona Sassenhagen`_.

- Add function :func:`mne.viz.plot_sensors` and methods :func:`mne.Epochs.plot_sensors`, :func:`mne.io.Raw.plot_sensors` and :func:`mne.Evoked.plot_sensors` for plotting sensor positions and :func:`mne.viz.plot_layout` and :func:`mne.channels.Layout.plot` for plotting layouts by `Jaakko Leppakangas`_

- Add epoch rejection based on annotated segments by `Jaakko Leppakangas`_

- Add option to use new-style MEG channel names in ``mne.read_selection`` by `Eric Larson`_

- Add option for ``proj`` in :class:`mne.EpochsArray` by `Eric Larson`_

- Enable the usage of :func:`mne.viz.plot_topomap` with an :class:`mne.Info` instance for location information, by `Jona Sassenhagen`_.

- Add support for electrocorticography (ECoG) channel type by `Eric Larson`_

- Add option for ``first_samp`` in :func:`mne.make_fixed_length_events` by `Jon Houck`_

- Add ability to auto-scale channel types for :func:`mne.viz.plot_raw` and :func:`mne.viz.plot_epochs` and corresponding object plotting methods by `Chris Holdgraf`_

BUG
~~~

- ``mne.time_frequency.compute_raw_psd``, ``mne.time_frequency.compute_epochs_psd``, :func:`mne.time_frequency.psd_multitaper`, and :func:`mne.time_frequency.psd_welch` no longer remove rows/columns of the SSP matrix before applying SSP projectors when picks are provided by `Chris Holdgraf`_.

- :func:`mne.Epochs.plot_psd` no longer calls a Welch PSD, and instead uses a Multitaper method which is more appropriate for epochs. Flags for this function are passed to :func:`mne.time_frequency.psd_multitaper` by `Chris Holdgraf`_

- Time-cropping functions (e.g., :func:`mne.Epochs.crop`, :func:`mne.Evoked.crop`, :func:`mne.io.Raw.crop`, :func:`mne.SourceEstimate.crop`) made consistent with behavior of ``tmin`` and ``tmax`` of :class:`mne.Epochs`, where nearest sample is kept. For example, for MGH data acquired with ``sfreq=600.614990234``, constructing ``Epochs(..., tmin=-1, tmax=1)`` has bounds ``+/-1.00064103``, and now ``epochs.crop(-1, 1)`` will also have these bounds (previously they would have been ``+/-0.99897607``). Time cropping functions also no longer use relative tolerances when determining the boundaries. These changes have minor effects on functions that use cropping under the hood, such as :func:`mne.compute_covariance` and ``mne.connectivity.spectral_connectivity``. Changes by `Jaakko Leppakangas`_ and `Eric Larson`_

- Fix EEG spherical spline interpolation code to account for average reference by `Mainak Jas`_

- MEG projectors are removed after Maxwell filtering by `Eric Larson`_

- Fix ``mne.decoding.TimeDecoding`` to allow specifying ``clf`` by `Jean-Remi King`_

- Fix bug with units (uV) in 'Brain Vision Data Exchange Header File Version 1.0' by `Federico Raimondo`_

- Fix bug where :func:`mne.preprocessing.maxwell_filter` ``destination`` parameter did not properly set device-to-head transform by `Eric Larson`_

- Fix bug in rank calculation of ``mne.utils.estimate_rank``, ``mne.io.Raw.estimate_rank``, and covariance functions where the tolerance was set to slightly too small a value, new 'auto' mode uses values from ``scipy.linalg.orth`` by `Eric Larson`_.

- Fix bug when specifying irregular ``train_times['slices']`` in ``mne.decoding.GeneralizationAcrossTime``, by `Jean-Remi King`_

- Fix colorbar range on norm data by `Jaakko Leppakangas`_

- Fix bug in ``mne.preprocessing.run_ica``, which used the ``ecg_criterion`` parameter for the EOG criterion instead of ``eog_criterion`` by `Christian Brodbeck`_

- Fix normals in CTF data reader by `Eric Larson`_

- Fix bug in :func:`mne.io.read_raw_ctf`, when omitting samples at the end by `Jaakko Leppakangas`_

- Fix ``info['lowpass']`` value for downsampled raw data by `Eric Larson`_

- Remove measurement date from :class:`mne.Info` in :func:`mne.io.Raw.anonymize` by `Eric Larson`_

- Fix bug that caused synthetic ecg channel creation even if channel was specified for ECG peak detection in :func:`mne.preprocessing.create_ecg_epochs` by `Jaakko Leppakangas`_

- Fix bug with vmin and vmax when None is passed in :func:`mne.viz.plot_topo_image_epochs` by `Jaakko Leppakangas`_

- Fix bug with :func:`mne.label_sign_flip` (and :func:`mne.extract_label_time_course`) by `Natalie Klein`_ and `Eric Larson`_

- Add copy parameter in :func:`mne.Epochs.apply_baseline` and :func:`mne.io.Raw.filter` methods by `Jona Sassenhagen`_ and `Alex Gramfort`_

- Fix bug in :func:`mne.merge_events` when using ``replace_events=False`` by `Alex Gramfort`_

- Fix bug in :class:`mne.Evoked` type setting in :func:`mne.stats.linear_regression_raw` by `Eric Larson`_

- Fix bug in ``mne.io.edf.RawEDF`` highpass filter setting to take max highpass to match warning message by `Teon Brooks`_

- Fix bugs with coordinane frame adjustments in ``mne.viz.plot_trans`` by `Eric Larson`_

- Fix bug in colormap selection in :func:`mne.Evoked.plot_projs_topomap` by `Jaakko Leppakangas`_

- Fix bug in source normal adjustment that occurred when 1) patch information is available (e.g., when distances have been calculated) and 2) points are excluded from the source space (by inner skull distance) by `Eric Larson`_

- Fix bug when merging info that has a field with list of dicts by `Jaakko Leppakangas`_

- The BTi/4D reader now considers user defined channel labels instead of the hard-ware names, however only for channels other than MEG. By `Denis Engemann`_ and `Alex Gramfort`_.

- The BTi reader :func:`mne.io.read_raw_bti` can now read 2500 system data, by `Eric Larson`_

- Fix bug in :func:`mne.compute_raw_covariance` where rejection by non-data channels (e.g. EOG) was not done properly by `Eric Larson`_.

- Change default scoring method of ``mne.decoding.GeneralizationAcrossTime`` and ``mne.decoding.TimeDecoding`` to estimate the scores within the cross-validation as in scikit-learn_ as opposed to across all cross-validated ``y_pred``. The method can be changed with the ``score_mode`` parameter by `Jean-Remi King`_

- Fix bug in :func:`mne.io.Raw.save` where, in rare cases, automatically split files could end up writing an extra empty file that wouldn't be read properly by `Eric Larson`_

- Fix :class:``mne.realtime.StimServer`` by removing superfluous argument ``ip`` used while initializing the object by `Mainak Jas`_.

- Fix removal of projectors in :func:`mne.preprocessing.maxwell_filter` in ``st_only=True`` mode by `Eric Larson`_

API
~~~

- The default ``picks=None`` in :func:`mne.viz.plot_epochs_image` now only plots the first 5 channels, not all channels, by `Jona Sassenhagen`_

- The ``mesh_color`` parameter in :func:`mne.viz.plot_dipole_locations` has been removed (use ``brain_color`` instead), by `Marijn van Vliet`_

- Deprecated functions ``mne.time_frequency.compute_raw_psd`` and ``mne.time_frequency.compute_epochs_psd``, replaced by :func:`mne.time_frequency.psd_welch` by `Chris Holdgraf`_

- Deprecated function ``mne.time_frequency.multitaper_psd`` and replaced by :func:`mne.time_frequency.psd_multitaper` by `Chris Holdgraf`_

- The ``y_pred`` attribute in ``mne.decoding.GeneralizationAcrossTime`` and ``mne.decoding.TimeDecoding`` is now a numpy array, by `Jean-Remi King`_

- The :func:`mne.bem.fit_sphere_to_headshape` function now default to ``dig_kinds='auto'`` which will use extra digitization points, falling back to extra plus eeg digitization points if there not enough extra points are available.

- The :func:`mne.bem.fit_sphere_to_headshape` now has a ``units`` argument that should be set explicitly. This will default to ``units='mm'`` in 0.12 for backward compatibility but change to ``units='m'`` in 0.13.

- Added default parameters in Epochs class namely ``event_id=None``, ``tmin=-0.2`` and ``tmax=0.5``.

- To unify and extend the behavior of :func:`mne.compute_raw_covariance` relative to :func:`mne.compute_covariance`, the default parameter ``tstep=0.2`` now discards any epochs at the end of the :class:`mne.io.Raw` instance that are not the full ``tstep`` duration. This will slightly change the computation of :func:`mne.compute_raw_covariance`, but should only potentially have a big impact if the :class:`mne.io.Raw` instance is short relative to ``tstep`` and the last, too short (now discarded) epoch contained data inconsistent with the epochs that preceded it.

- The default ``picks=None`` in :func:`mne.io.Raw.filter` now picks eeg, meg, seeg, and ecog channels, by `Jean-Remi King`_ and `Eric Larson`_

- EOG, ECG and EMG channels are now plotted by default (if present in data) when using :func:`mne.viz.plot_evoked` by `Marijn van Vliet`_

- Replace pseudoinverse-based solver with much faster Cholesky solver in :func:`mne.stats.linear_regression_raw`, by `Jona Sassenhagen`_.

- CTF data reader now reads EEG locations from .pos file as HPI points by `Jaakko Leppakangas`_

- Subselecting channels can now emit a warning if many channels have been subselected from projection vectors. We recommend only computing projection vertors for and applying projectors to channels that will be used in the final analysis. However, after picking a subset of channels, projection vectors can be renormalized with :func:`mne.Info.normalize_proj` if necessary to avoid warnings about subselection. Changes by `Eric Larson`_ and `Alex Gramfort`_.

- Rename and deprecate ``mne.Epochs.drop_bad_epochs`` to :func:`mne.Epochs.drop_bad`, and ``mne.Epochs.drop_epochs`` to :func:`mne.Epochs.drop` by `Alex Gramfort`_.

- The C wrapper ``mne.do_forward_solution`` has been deprecated in favor of the native Python version :func:`mne.make_forward_solution` by `Eric Larson`_

- The ``events`` parameter of :func:`mne.EpochsArray` is set by default to chronological time-samples and event values to 1, by `Jean-Remi King`_

Authors
~~~~~~~

The committer list for this release is the following (preceded by number of commits):

* 348	Eric Larson
* 347	Jaakko Leppakangas
* 157	Alexandre Gramfort
* 139	Jona Sassenhagen
* 67	Jean-Remi King
* 32	Chris Holdgraf
* 31	Denis A. Engemann
* 30	Mainak Jas
* 16	Christopher J. Bailey
* 13	Marijn van Vliet
* 10	Mark Wronkiewicz
* 9	Teon Brooks
* 9	kaichogami
* 8	Clément Moutard
* 5	Camilo Lamus
* 5	mmagnuski
* 4	Christian Brodbeck
* 4	Daniel McCloy
* 4	Yousra Bekhti
* 3	Fede Raimondo
* 1	Jussi Nurminen
* 1	MartinBaBer
* 1	Mikolaj Magnuski
* 1	Natalie Klein
* 1	Niklas Wilming
* 1	Richard Höchenberger
* 1	Sagun Pai
* 1	Sourav Singh
* 1	Tom Dupré la Tour
* 1	jona-sassenhagen@
* 1	kambysese
* 1	pbnsilva
* 1	sviter
* 1	zuxfoucault
