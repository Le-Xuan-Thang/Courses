import subprocess

def wsl_to_windows_path(wsl_path):
    """Convert a WSL path to a Windows path."""
    try:
        win_path = subprocess.check_output(['wslpath', '-w', wsl_path], text=True).strip()
        return win_path
    except Exception as e:
        raise RuntimeError(f"Error converting WSL path to Windows path: {e}")

def windows_to_wsl_path(win_path):
    """Convert a Windows path to a WSL path."""
    try:
        wsl_path = subprocess.check_output(['wslpath', '-u', win_path], text=True).strip()
        return wsl_path
    except Exception as e:
        raise RuntimeError(f"Error converting Windows path to WSL path: {e}")
