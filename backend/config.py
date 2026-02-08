# config.py
# Thresholds & calibration params

THRESHOLDS = {
    'heart_rate_min': 60,
    'heart_rate_max': 100,
    'breathing_rate_min': 12,
    'breathing_rate_max': 20,
    'temperature_min': 36.0,
    'temperature_max': 37.5,
}

CALIBRATION_PARAMS = {
    'csi_sensitivity': 0.8,
    'noise_threshold': 0.1,
    'filter_order': 4,
}
